set -e

rm -r toolchain/opt/work/llvm/install/include/*
cp -r Compiler/llvm/projects/ton-compiler/cpp-sdk/* toolchain/opt/work/llvm/install/include/

python3 toolchain/opt/work/llvm/install/bin/tvm-build++.py \
--abi src/Contract.abi \
--cxxflags="-Ilibs/algebra/include \
-Ilibs/block/include \
-Ilibs/blueprint/include \
-Ilibs/hash/include \
-Ilibs/marshalling/core/include \
-Ilibs/marshalling/zk/include \
-Ilibs/marshalling/algebra/include \
-Ilibs/marshalling/multiprecision/include \
-Ilibs/math/include \
-Ilibs/multiprecision/include \
-Ilibs/random/include \
-Ilibs/zk/include" \
 src/Contract.cpp \
-o bin/Contract.tvc
