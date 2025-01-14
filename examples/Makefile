# Use wildcard to find directories
EXAMPLES := $(wildcard example_*/)

# Declare phony targets
.PHONY: all $(EXAMPLES)

# Define 'all' to depend on all example directories
all: $(EXAMPLES)

# Rule for processing each directory
$(EXAMPLES):
	cd $@ && cmake -B build -DCMAKE_TOOLCHAIN_FILE=../../build/Debug/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug . && make -C build
