#!/bin/bash

set -e

source $(dirname "$0")/install-system.sh

if [ ! -d "dependencies" ]; then
    echo "The dependencies directory does not exist"
    exit 1
fi

cd dependencies

cd zlib-*
sudo cmake --build build --config Release --target install

cd ..

cd jemalloc-*
sudo make install

cd ..

cd zstd-*/build/cmake
sudo cmake --build build --config Release --target install

cd ../../..

cd rocksdb-*
sudo cmake --build build --config Release --target install

cd ..

cd fmt-*
sudo cmake --build build --config Release --target install

cd ..

cd spdlog-*
sudo cmake --build build --config Release --target install

cd ..

cd benchmark-*
sudo cmake --build build --config Release --target install

cd ..

cd googletest-release-*
sudo cmake --build build --config Release --target install

cd ..

cd mysql-connector-cpp-*
sudo cmake --build build --config Release --target install

cd ..

cd magic_enum-*
sudo cmake --build build --config Release --target install

cd ..

cd json-*
sudo cmake --build build --config Release --target install

cd ..

cd protobuf-*
sudo make install

cd ..

cd libarchive-*
sudo cmake --build build --config Release --target install

cd ..

cd curl-curl-*
sudo cmake --build build --config Release --target install

cd ..

cd icu/source
sudo make install

cd ../..

cd boost_*
sudo ./b2 --toolset=gcc-10 --with-program_options install

cd ..

cd ..

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    sudo ldconfig
elif [[ "$OSTYPE" == "darwin"* ]]; then
    sudo update_dyld_shared_cache
fi

echo "Install completed"
