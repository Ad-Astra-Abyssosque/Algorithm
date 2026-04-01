//
// Created by wcx on 2026/3/25.
//

#ifndef ALGORITHM_LONGESTPALINDROME_H
#define ALGORITHM_LONGESTPALINDROME_H
#include "../../../Solution.h"
#include <string>

using namespace std;

class LongestPalindrome: public Solution
{
public:
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            string tmp = findSubstring(s, i, i);
            if (tmp.length() > ans.length()) { ans = std::move(tmp); }
            tmp = findSubstring(s, i, i + 1);
            if (tmp.length() > ans.length()) { ans = std::move(tmp); }
        }
        return ans;
    }

    string findSubstring(string& s, int forward, int backward)
    {
        while (forward >= 0 && backward < s.length())
        {
            if (s[forward] != s[backward])
            {
                break;
            }
            forward--;
            backward++;
        }
        forward++;
        backward--;
        return s.substr(forward, backward - forward + 1);
    }

};


#endif //ALGORITHM_LONGESTPALINDROME_H