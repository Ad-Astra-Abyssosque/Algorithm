//
// Created by User on 2026/4/7.
//

#ifndef ALGORITHM_DECODESTRING_H
#define ALGORITHM_DECODESTRING_H

#include "../../../Solution.h"
#include <string>

using namespace std;

class DecodeString: public Solution {
public:
    string decodeString(string s) {
        string ans;
        work(s, ans, 0);
        return ans;
    }

    int getNum(const string& origin, int& index) {
        int start = index;
        while (index < origin.length()) {
            char c = origin[index];
            if (c > '9') { break; }
            index++;
        }
        return stoi(origin.substr(start, index - start));
    }

    int work(const string& origin, string& ans, int start) {
        int repeat = -1;
        int index = start;
        while (index < origin.length()) {
            char c = origin[index];
            if (c <= '9') {
                repeat = getNum(origin, index);
                string tmp;
                index = work(origin, tmp, index);
                for (int i = 0; i < repeat; i++) {
                    ans += tmp;
                }
            }
            else if (c <= 'z' && c >= 'a' ) {
                ans += c;
            }
            else if (c == ']') {
                return index;
            }
            index++;
        }
        return index;
    }

    virtual void main() override {
        string s = "10[leetcode]";
        cout << decodeString(s) << endl;
    }
};

#endif //ALGORITHM_DECODESTRING_H
