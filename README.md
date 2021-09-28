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
$ cmake -DCMAKE_INSTALL_PREFIX=../../toolchain/opt/work/llvm/install -DCMAKE_BUILD_TYPE=Release -DCMAKE_LINKER=lld -GNinja -C ../cmake/Cache/ton-compiler.cmake ../llvm
$ cmake --build . --target install-distribution
```

## Repository Contents

src folder contains a file named circuit.hpp which contains an example circuit definition, and main.cpp which is a simple Console app Contract.cpp which is a contract, both use circuit.hpp.

the libs folder contains the crypto3-blueprint library and its dependencies, as well as the marshalling library.

You've got two build scripts:
* ./build_executable - would build src/main.cpp to bin/executable, it should work out of the box (It assumes you have g++ and boost installed though). It is meant for making sure there are no mistakes in circuit.hpp.
* ./build_contract - would build src/Contract.cpp to bin/Contract.tvc, it should have compiling errors and is meant to demosntrate the problems in the C++ SDK.

If you modify other parts of the compiler, you might have to build the Compiler yourself for the changes to take effect.
