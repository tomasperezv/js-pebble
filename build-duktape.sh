#!/bin/bash

cd duktape
make clean
make -j4
cp dist/src/* ../src/

