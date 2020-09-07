//
// Created by kaiser on 19-3-22.
//

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    // 拷贝文件或目录
    // 若目标位置文件已存在则抛出异常
    fs::copy("CMakeFiles/progress.marks", ".");
    fs::copy("CMakeFiles/progress.marks", "fuck.txt");

    // 将目录里的文件拷贝出来(不包括文件夹)
    fs::copy("CMakeFiles/any.dir", ".");
    // 将目录里的文件到目标目录(不包括文件夹)
    fs::copy("CMakeFiles/any.dir", "fuck");
    // 将目录里的文件到目标目录(包括文件夹及里面的内容)
    fs::copy("CMakeFiles/any.dir", "fuck",
             std::filesystem::copy_options::recursive);

    // 拷贝单个文件
    // 若目标位置文件已存在则抛出异常
    // 若文件被复制则返回 true , 否则返回 false
    fs::copy_file("CMakeFiles/progress.marks", "fuck.txt");
}
