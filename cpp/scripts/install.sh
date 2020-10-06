#!/bin/bash

set -e

if [ ! -d "dependencies" ]; then
    echo "The dependencies directory does not exist"
    exit 1
fi

source $(dirname "$0")/install-system.sh

cd dependencies

cd zlib-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install zlib completed"

cd jemalloc-*
sudo make install
cd ..
echo "Install jemalloc completed"

cd zstd-*/build/cmake
sudo cmake --build build --config Release --target install
cd ../../..
echo "Install zstd completed"

cd rocksdb-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install rocksdb completed"

cd fmt-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install fmt completed"

cd spdlog-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install spdlog completed"

cd benchmark-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install google benchmark completed"

cd googletest-release-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install google test completed"

cd mysql-connector-cpp-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install mysql connector completed"

cd magic_enum-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install magic enum completed"

cd json-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install json completed"

cd protobuf-*
sudo make install
cd ..
echo "Install protobuf completed"

cd libarchive-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install libarchive completed"

cd curl-curl-*
sudo cmake --build build --config Release --target install
cd ..
echo "Install curl completed"

cd icu/source
sudo make install
cd ../..
echo "Install icu completed"

cd boost_*
sudo ./b2 --toolset=gcc-10 --with-program_options install
cd ..
echo "Install boost completed"

cd ..

sudo ldconfig

echo "Install completed"
