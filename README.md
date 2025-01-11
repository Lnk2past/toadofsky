# Toadofsky

This is an educational endeavor into learning a bit more about multithreading, messaging, and *orchestration* using C++20. Some goals, which will absolutely change as I experiement and mess around with it all:

* Orchestration of (synchronization between) threads should be be flexible, should be able to switch between synchronous, asynchronous + fixed rate synchronization, and purely asynchronous
* Messages sent between models should copy as little data as possible; make use of moves, pointers, etc.
    * this is tough, how do you enforce copying underlying data when you need to persist it? e.g. a large object is sent via pointer and a receiver of the data holds onto that pointer. That data can change out from under the receiver, or potentially now the sender. 
* Many-to-many messaging
* Messages carry provenance (minimally who sent it, when it was sent)
* Implement a thread-pool to allow for using a restricted number of resources (e.g. multithread 4 models across 2 threads)
* Top-to-bottom configurable via file (plan to use `nlohmann/json`)

<center><img src="toadofsky.png" width="120"></center>

## Development

Devcontainer provided; just launch a Codespace or local devcontainer!

### Build

This project uses Conan + CMake for dependency management and builds. You will need to install dependencies via Conan and then build via CMake (there are VSCode build tasks for these!):

```shell
# install dependencies
conan install . --build=missing

# load preset
cmake --preset conan-release

# build code
cmake --build --preset conan-release
```

## Examples

Check out [`examples`](./exmaples) for some basic usage. Need to script building these...
