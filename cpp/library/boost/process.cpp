#include <iostream>
#include <string>
#include <vector>

#include <boost/process/child.hpp>
#include <boost/process/io.hpp>
#include <boost/process/pipe.hpp>

int main()
{
    boost::process::ipstream is;
    boost::process::child c{"/usr/bin/gcc-10", "-v",
                            boost::process::std_out > is};

    std::vector<std::string> data;
    std::string line;

    while (c.running() && std::getline(is, line)) {
        data.push_back(line);
    }

    c.wait();

    for (const auto& item : data) {
        std::cout << item << '\n';
    }
}
