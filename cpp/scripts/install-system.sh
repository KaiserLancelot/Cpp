#!/bin/bash

set -e

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    sudo add-apt-repository ppa:ubuntu-toolchain-r/ppa
    sudo apt update
    sudo apt install gcc-10 g++-10

    export CC=gcc-10
    export CXX=g++-10
else
    echo "The system does not support: $OSTYPE"
    exit 1
fi
