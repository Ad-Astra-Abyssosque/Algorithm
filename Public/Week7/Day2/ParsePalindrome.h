//
// Created by wcx on 2026/4/12.
//

#ifndef ALGORITHM_PARSEPALINDROME_H
#define ALGORITHM_PARSEPALINDROME_H
#include "../../../Solution.h"
#include <string>

using namespace std;

class ParsePalindrome: Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        auto tmp = work(s, 0);
        vector<vector<string>> ans;
        for (auto& candidate: tmp)
        {
            bool flag = true;
            for (string& str: candidate)
            {
                if (!isPalindrome(str))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                // sort(candidate.begin(), candidate.end());
                ans.emplace_back(std::move(candidate));
            }
        }
        return ans;
    }

    vector<vector<string>> work(const string& str, int start)
    {
        vector<vector<string>> ret;
        for (int i = start; i < str.length(); i++)
        {
            string tmp = str.substr(start, i - start + 1);
            if (!isPalindrome(tmp)) { continue; }
            vector<vector<string>> sub_parse = work(str, i + 1);
            if (sub_parse.empty()) { ret.emplace_back(1, tmp); }
            for (vector<string>& v: sub_parse)
            {
                v.insert(v.begin(), tmp);
                ret.emplace_back(v);
            }
        }
        return ret;
    }

    bool isPalindrome(const string& str)
    {
        if (str.length() == 1) { return true; }
        int start = 0;
        int end = str.length() - 1;
        while (start <= end)
        {
            if (str[start] == str[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    virtual void main() override
    {
        string s = "aab";
        auto res = partition(s);
        for (vector<string>& arr: res)
        {
            for (string& str: arr)
            {
                cout << str << " ";
            }
            cout << endl;
        }
    }
};

#endif //ALGORITHM_PARSEPALINDROME_H