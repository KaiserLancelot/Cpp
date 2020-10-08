#!/bin/bash

set -e

source $(dirname "$0")/install-system.sh

if [ ! -d "dependencies" ]; then
    echo "mkdir dependencies"
    mkdir dependencies
fi

cd dependencies

# zlib
if [ ! -f "zlib-1.2.11.zip" ]; then
    wget -q https://github.com/madler/zlib/archive/v1.2.11.zip -O zlib-1.2.11.zip
fi
unzip -q zlib-*.zip
rm zlib-*.zip
cd zlib-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install zlib completed"

# jemalloc
if [ ! -f "jemalloc-5.2.1.zip" ]; then
    wget -q https://github.com/jemalloc/jemalloc/archive/5.2.1.zip -O jemalloc-5.2.1.zip
fi
unzip -q jemalloc-*.zip
rm jemalloc-*.zip
cd jemalloc-*
./autogen.sh
make -j$(nproc)
sudo make install
cd ..
echo "Build and jemalloc completed"

# zstd
if [ ! -f "zstd-1.4.5.zip" ]; then
    wget -q https://github.com/facebook/zstd/archive/v1.4.5.zip -O zstd-1.4.5.zip
fi
unzip -q zstd-*.zip
rm zstd-*.zip
cd zstd-*/build/cmake
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DZSTD_BUILD_PROGRAMS=OFF -DZSTD_BUILD_TESTS=OFF
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ../../..
echo "Build and install zstd completed"

# rocksdb
if [ ! -f "rocksdb-6.11.4.zip" ]; then
    wget -q https://github.com/facebook/rocksdb/archive/v6.11.4.zip -O rocksdb-6.11.4.zip
fi
unzip -q rocksdb-*.zip
rm rocksdb-*.zip
cd rocksdb-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DWITH_JEMALLOC=ON -DWITH_ZSTD=ON -DWITH_GFLAGS=OFF \
    -DUSE_RTTI=ON -DWITH_RUNTIME_DEBUG=OFF -DROCKSDB_BUILD_SHARED=ON \
    -DWITH_TESTS=OFF -DWITH_BENCHMARK_TOOLS=OFF -DWITH_CORE_TOOLS=OFF \
    -DWITH_TOOLS=OFF -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install rocksdb completed"

# fmt
if [ ! -f "fmt-7.0.3.zip" ]; then
    wget -q https://github.com/fmtlib/fmt/archive/7.0.3.zip -O fmt-7.0.3.zip
fi
unzip -q fmt-*.zip
rm fmt-*.zip
cd fmt-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DFMT_DOC=OFF -DFMT_TEST=OFF -DBUILD_SHARED_LIBS=TRUE
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install fmt completed"

# spdlog
if [ ! -f "spdlog-1.8.1.zip" ]; then
    wget -q https://github.com/gabime/spdlog/archive/v1.8.1.zip -O spdlog-1.8.1.zip
fi
unzip -q spdlog-*.zip
rm spdlog-*.zip
cd spdlog-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DSPDLOG_BUILD_EXAMPLE=OFF -DSPDLOG_FMT_EXTERNAL=ON \
    -DSPDLOG_BUILD_SHARED=ON
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install spdlog completed"

# google benchmark
if [ ! -f "benchmark-1.5.2.zip" ]; then
    wget -q https://github.com/google/benchmark/archive/v1.5.2.zip -O benchmark-1.5.2.zip
fi
unzip -q benchmark*.zip
rm benchmark*.zip
cd benchmark-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DBENCHMARK_ENABLE_TESTING=OFF -DBENCHMARK_ENABLE_LTO=ON \
    -DBENCHMARK_USE_LIBCXX=OFF -DBENCHMARK_ENABLE_GTEST_TESTS=OFF \
    -DBENCHMARK_ENABLE_ASSEMBLY_TESTS=OFF -DBUILD_SHARED_LIBS=ON
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install google benchmark completed"

# google test
if [ ! -f "googletest-release-1.10.0.zip" ]; then
    wget -q https://github.com/google/googletest/archive/release-1.10.0.zip \
        -O googletest-release-1.10.0.zip
fi
unzip -q googletest-release-*.zip
rm googletest-release-*.zip
cd googletest-release-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_GMOCK=OFF -DBUILD_SHARED_LIBS=ON
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install google test completed"

# mysql connector
if [ ! -f "mysql-connector-cpp-8.0.21.zip" ]; then
    wget -q https://github.com/mysql/mysql-connector-cpp/archive/8.0.21.zip \
        -O mysql-connector-cpp-8.0.21.zip
fi
unzip -q mysql-connector-cpp-*.zip
rm mysql-connector-cpp-*.zip
cd mysql-connector-cpp-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_STATIC=OFF -DWITH_TESTS=OFF \
    -DCMAKE_INSTALL_PREFIX=/usr/local -DCMAKE_INSTALL_LIBDIR=lib
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install mysql connector completed"

# magic enum
if [ ! -f "magic_enum-0.6.6.zip" ]; then
    wget -q https://github.com/Neargye/magic_enum/archive/v0.6.6.zip -O magic_enum-0.6.6.zip
fi
unzip -q magic_enum-*.zip
rm magic_enum-*.zip
cd magic_enum-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DMAGIC_ENUM_OPT_BUILD_EXAMPLES=OFF -DMAGIC_ENUM_OPT_BUILD_TESTS=OFF
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install magic enum completed"

# json
if [ ! -f "json-3.9.1.zip" ]; then
    wget -q https://github.com/nlohmann/json/archive/v3.9.1.zip -O json-3.9.1.zip
fi
unzip -q json-*.zip
rm json-*.zip
cd json-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DJSON_BuildTests=OFF -DJSON_MultipleHeaders=ON
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install json completed"

# protobuf
if [ ! -f "protobuf-cpp-3.13.0.zip" ]; then
    wget -q https://github.com/protocolbuffers/protobuf/releases/download/v3.13.0/protobuf-cpp-3.13.0.zip \
        -O protobuf-cpp-3.13.0.zip
fi
unzip -q protobuf-cpp-*.zip
rm protobuf-cpp-*.zip
cd protobuf-*
./configure
make -j$(nproc)
sudo make install
cd ..
echo "Build and install protobuf completed"

# libarchive
if [ ! -f "libarchive-3.4.3.zip" ]; then
    wget -q https://github.com/libarchive/libarchive/archive/v3.4.3.zip \
        -O libarchive-3.4.3.zip
fi
unzip -q libarchive-*.zip
rm libarchive-*.zip
cd libarchive-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DENABLE_OPENSSL=OFF -DENABLE_LIBB2=OFF -DENABLE_LZ4=OFF \
    -DENABLE_LZO=OFF -DENABLE_LZMA=OFF -DENABLE_ZSTD=ON \
    -DENABLE_ZLIB=OFF -DENABLE_BZip2=OFF -DENABLE_LIBXML2=OFF \
    -DENABLE_EXPAT=OFF -DENABLE_CNG=OFF -DENABLE_TAR=OFF \
    -DENABLE_CPIO=OFF -DENABLE_CAT=OFF -DENABLE_XATTR=OFF \
    -DENABLE_ACL=OFF -DENABLE_ICONV=OFF -DENABLE_TEST=OFF
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install libarchive completed"

# curl
if [ ! -f "curl-curl-7_72_0.zip" ]; then
    wget -q https://github.com/curl/curl/archive/curl-7_72_0.zip -O curl-curl-7_72_0.zip
fi
unzip -q curl-curl-*.zip
rm curl-curl-*.zip
cd curl-curl-*
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_CURL_EXE=OFF -DBUILD_SHARED_LIBS=ON \
    -DCURL_LTO=ON -DHTTP_ONLY=ON -DENABLE_MANUAL=OFF \
    -DCURL_ZLIB=OFF -DCURL_ZSTD=OFF -DBUILD_TESTING=OFF
cmake --build build --config Release -j$(nproc)
sudo cmake --build build --config Release --target install
cd ..
echo "Build and install curl completed"

# icu
if [ ! -f "icu4c-67_1-src.tgz" ]; then
    wget -q https://github.com/unicode-org/icu/releases/download/release-67-1/icu4c-67_1-src.tgz \
        -O icu4c-67_1-src.tgz
fi
tar -xf icu4c-*-src.tgz
rm icu4c-*-src.tgz
cd icu/source
./configure --enable-tests=no --enable-samples=no
make -j$(nproc)
sudo make install
cd ../..
echo "Build and install icu completed"

# boost
if [ ! -f "boost_1_74_0.tar.gz" ]; then
    wget -q https://dl.bintray.com/boostorg/release/1.74.0/source/boost_1_74_0.tar.gz \
        -O boost_1_74_0.tar.gz
fi
tar -xf boost_*.tar.gz
rm boost_*.tar.gz
cd boost_*
./bootstrap.sh
./b2 --toolset=gcc-10 --with-program_options
sudo ./b2 --toolset=gcc-10 --with-program_options install
cd ..
echo "Build and install boost completed"

cd ..

sudo ldconfig

echo "Build and install completed"
