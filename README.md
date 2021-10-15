## Get Started
### Get the code
``` bash
git clone --recursive git@github.com:NoamDev/crypto3_blueprint-to-tvm-compilation-contest.git contest && cd contest
```
### Building the Compiler

#### Requirements
* GCC 7.3.0 or newer
* Rust 1.47.0 or newer
* Cargo
* ninja-build
* lld

It can be built without ninja and lld, but it would take longer. For more compilation options see: https://github.com/tonlabs/TON-Compiler/blob/master/README.md

``` bash
$ cd Compiler
$ mkdir build && cd build
$ cmake -DCMAKE_INSTALL_PREFIX=../../toolchain/opt/work/llvm/install \
  -DCMAKE_BUILD_TYPE=Release -DCMAKE_LINKER=lld -GNinja \
  -C  ../cmake/Cache/ton-compiler.cmake ../llvm
$ cmake --build . --target install-distribution
```

Subsequent Builds can be done with just runnning from `Compiler/build`:
``` bash
$ cmake --build . --target install-distribution
```
They should be very fast if no substantial changes were made.

## Repository Contents

* `src/circuit.hpp` - Contains an example circuit definition and can generate primary and auxiliary inputs.
* `src/main.cpp` - A simple CLI app which includes `src/circuit.hpp` and prints the size of the primary and auxiliary inputs.
* `src/contract.cpp` - A contract which includes `src/circuit.hpp` and has a getter that would return primary and auxiliary inputs for a given parameters.

* `libs` - contains the crypto3-blueprint library and its dependencies, as well as the marshalling library.

* `Compiler` - contains the source code of the compiler, building as per instructions above should install it the binaries in the directory `toolchain`.

## Building the CLI app.
The CLI app is mostly meant as a way to make sure there is nothing wrong with circuit.hpp.
Requirements: Boost >= 1.74.
``` bash
./build_executable.sh
```
Should produce a binary on `bin/executable`.

## Building the contract.
The contract building would result in an error unless you do something about it:).
Mostly about missing header files.

``` bash
./build_contract
```
if successful a file `Contract.tvc` should appear in the directory `bin`. Its ABI file is already in the `src` directory.

## A note about git submodules
the directories under `libs` as well as the directory `Compiler` are git submodules. If you decide to change any of them, you should fork the original reposiories and change the submodule to point to your fork.
