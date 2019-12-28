#!/bin/bash

if [ ! -e Compiler ]; then
    echo "test-err: Compiler does not exist."
    exit 1
fi

./Compiler $@

if [ $? -ne 0 ]; then
    echo "test-err: failed to compile."
    exit 1
fi

gcc as.s -O0

if [ $? -ne 0 ]; then
    echo "test-err: failed to assemble."
    exit 1
fi

./a.out

echo "echo \$?: $?"