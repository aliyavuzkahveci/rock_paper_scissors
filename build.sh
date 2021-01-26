#!/bin/bash

# removing previously built binary
rm rock_paper_scissors

# cleaning old build
rm -rf build/

# creating build folder
mkdir build

cd build/

# preparation of Makefile
cmake ..

# compile & build
make

# running unit tests
../runUnitTests.sh

# go back to parent dir
cp rock_paper_scissors ../
cd ..

# starting binary
#./rock_paper_scissors --mode Auto --name IMC -r 5 -v
