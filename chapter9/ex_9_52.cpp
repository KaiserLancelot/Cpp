//
// Created by kaiser on 18-12-5.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>

int main() {
    std::string expr("I am (Kaiser)");

    std::stack<char> stack;
    bool left{};
    for (auto c:expr) {
        stack.push(c);
        if (c == '(') {
            left = true;
        }
        if (c == ')' && left) {
            while (stack.top() != '(') {
                stack.pop();
            }
            stack.pop();
            stack.push('1');
        }
    }

    std::string result;
    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }

    std::cout << std::string(std::rbegin(result), std::rend(result)) << '\n';
}