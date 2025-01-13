#pragma once

#include <filesystem>
#include <memory>
#include <stdexcept>
#include <type_traits>

namespace toadofsky
{
#ifdef _WIN32
#include <windows.h>
    using LibraryHandle = HMODULE;
#define load_library(path) LoadLibraryA(path.string().c_str())
#define get_symbol(handle, name) GetProcAddress(handle, name)
#define unload_library FreeLibrary
#else
#include <dlfcn.h>
    using LibraryHandle = void *;
#define load_library(path) dlopen(path.c_str(), RTLD_NOW)
#define get_symbol(handle, name) dlsym(handle, name)
#define unload_library dlclose
#endif

    static inline auto delete_library_handle(LibraryHandle handle) -> void
    {
        if (handle)
        {
            unload_library(handle);
        }
    }

    struct DynamicLibrary
    {
        explicit DynamicLibrary(const std::filesystem::path &libraryPath) : handle(nullptr, delete_library_handle)
        {
            handle.reset(load_library(libraryPath));
            if (!handle)
            {
                throw std::runtime_error("Failed to load library");
            }
        }

        template <typename FuncT>
        auto get_function(const std::string &symbol_name) -> FuncT
        {
            auto func = get_symbol(handle.get(), symbol_name.c_str());
            if (!func)
            {
                throw std::runtime_error("Failed to get function: " + symbol_name);
            }
            return reinterpret_cast<FuncT>(func);
        }

    private:
        std::unique_ptr<std::remove_pointer_t<LibraryHandle>, void (*)(LibraryHandle)> handle;
    };
}