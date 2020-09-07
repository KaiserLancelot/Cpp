//
// Created by kaiser on 18-12-5.
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main()
{
    std::string expr("I am (Kaiser))");

    std::stack<char> stack;
    std::stack<bool> left;
    for (auto c : expr) {
        stack.push(c);
        if (c == '(') {
            left.push(true);
        }
        if (c == ')' && !left.empty() && left.top()) {
            while (stack.top() != '(') {
                stack.pop();
            }
            stack.pop();
            stack.push('1');
            left.pop();
        }
    }

    std::string result;
    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }

    std::cout << std::string{std::rbegin(result), std::rend(result)} << '\n';
}
