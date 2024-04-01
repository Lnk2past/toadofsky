# Toadofsky

This is an educational endeavor into learning a bit more about multithreading, orchestration, and messaging using C++20. Some goals, which will absolutely change as I experiement and mess around with it all:

* Orchestration of (synchronization between) threads should be be flexible, should be able to switch between synchronous, asynchronous + fixed rate synchronization, and purely asynchronous
* Messages sent between models should copy as little data as possible; make use of moves, pointers, etc.
* Many-to-many messaging
* Messages carry provenance (minimally who sent it, when it was sent)
* Implement a thread-pool to allow for using a restricted number of resources (e.g. multithread 4 models across 2 threads)
* Defer model/data IO to a separate thread
* Top-to-bottom configurable via file (plan to use `nlohmann/json`)

Other things that I have't wrapped my head around yet:

* Ownership - who should own the models? The messages? Currently:
    * The orchestrator own models; until I implement a configuration system `main.cpp` creates models and registers them with the orchestrator; orchestrator assumes control over lifetime
    * Noone/everyone owns messages; they are created in the broker and distributed as `std::shared_ptr` 
* Rate limiting
    * Some models should tick at different rates than others, and most models will not spin unrestricted. How should run loops be implemented to do this?
    * Naive approach would be to sleep for different amounts of time to limit when threads update, but this does not take into account time to process the tick
        * e.g. if `ModelA` should tick every 1 second, but an update takes anywhere between 0.1 and 0.5 seconds, sleeping the thread for a fixed amount would not yield the correct timing
    * Maybe check if the "current time" has advanced far enough to trigger an update on a thread?
        * This feels like it would work well with the "purely asychronous" setup
        * This feels like it would not work well with the desired "asynchronous + fixed rate synchronization" setup
            * e.g. if `ModelA` should tick every 0.333 seconds, but the orchestrator is ticking at a fixed rate of 0.25 seconds, then the tick at t=0.5s means that `Model` would update ~0.167s later than anticipates
        * Would like to avoid an explicit scheduler for reasons I haven't worked out yet, but this seems like it would be needed to better utilize a threadpool anyway 

## Development

Devcontainer provided; just launch a Codespace or local devcontainer!

### Build

This project uses Conan + CMake for dependency management and builds. Use the default build task in VSCode (`Ctrl + Shift + B`) or build in the terminal:

shell
```
conan build . --build=missing -s build_type=Debug
```

This will produce a debug build. If you would like a release build, then run the other build task or build in the terminal: 

shell
```
conan build . --build=missing
```

### Running

There is a debug launch configuration if you need debugging, but otherwise you can run from the terminal, where `<CONFIG>` is either `Release` or `Debug`, whichever you are trying to execute:

```shell
./build/<CONFIG>/src/toadofsky
```

## Mascot

![](toadofsky.png)

