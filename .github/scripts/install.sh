#!/bin/sh -e

cd dependencies

cd zlib-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd jemalloc-*
sudo make install
sudo ldconfig

cd ..

cd zstd-*/build/cmake
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ../../..

cd rocksdb-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd fmt-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd benchmark-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd googletest-release-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd mysql-connector-cpp-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd magic_enum-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd json-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd protobuf-*
sudo make install
sudo ldconfig

cd ..

cd libarchive-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd curl-curl-*
sudo cmake --build build --config Release --target install
sudo ldconfig

cd ..

cd icu/source
sudo make install
sudo ldconfig

cd ../..

cd boost_*
./b2 --toolset=gcc-10 --with-program_options build
sudo ./b2 install
sudo ldconfig

cd ..

cd ..

echo "Install completed"
