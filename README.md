## Get Started
* `git clone --recursive git@github.com:NoamDev/crypto3_blueprint-to-tvm-compilation-contest.git contest && cd contest`
* download already built C++ to TVM compiler for [Linux](https://binaries.tonlabs.io/clang-for-tvm/clang-for-tvm-7_7_22-linux.tar.gz), [Windows](https://binaries.tonlabs.io/clang-for-tvm/clang-for-tvm-7_7_22-win32.zip) or [Mac](https://binaries.tonlabs.io/clang-for-tvm/clang-for-tvm-7_7_22-darwin.zip)
* Extract the archive you downloaded on the previous step to `contest/toolchain`.

## Repository Contents

src folder contains a file named circuit.hpp which contains an example circuit definition, and main.cpp which is a simple Console app Contract.cpp which is a contract, both use circuit.hpp.

the libs folder contains the crypto3-blueprint library and its dependencies, as well as the marshalling library.

The folder Compiler contains the source code of the C++ compiler, you can build it yourself instead of downloading the prebuilt toolchain, but note that this can be time and disk space consuming.  You can do that according to the instructions at the README of https://github.com/tonlabs/TON-Compiler.

You've got two build scripts:
* ./build_executable - would build src/main.cpp to bin/executable, it should work out of the box (It assumes you have g++ and boost installed though). It is meant for making sure there are no mistakes in circuit.hpp.
* ./build_contract - would build src/Contract.cpp to bin/Contract.tvc, it should have compiling errors and is meant to demosntrate the problems in the C++ SDK.

The C++ SDK is in Compiler/llvm/projects/ton-compiler/cpp-sdk. build_contract would copy it before building the contract to toolchain/opt/work/llvm/install/include so that the compiler would use it.

If you modify other parts of the compiler, you might have to build the Compiler yourself for the changes to take effect.
