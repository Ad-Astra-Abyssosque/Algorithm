//
// Created by wcx on 2026/2/12.
//

#ifndef ALGORITHM_VALIDPARENTHESES_H
#define ALGORITHM_VALIDPARENTHESES_H

#include <stack>
#include <string>

class ValidParentheses {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (const char& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else {
                if (stack.empty()) {
                    return false;
                }
                if ((c == ')' && stack.top() == '(') || (c == '}' && stack.top() == '{') || (c == ']' && stack.top() == '[')) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};

#endif //ALGORITHM_VALIDPARENTHESES_H