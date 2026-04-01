//
// Created by wcx on 2026/3/24.
//

#ifndef ALGORITHM_WORDBREAK_H
#define ALGORITHM_WORDBREAK_H
#include "../../../Solution.h"

#include <string>
#include <unordered_map>

using namespace std;

class WordBreak: Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> table;
        for (const string& word: wordDict)
        {
            table[word] = 1;
        }
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            // if (table.find(s.substr(0, i)) != table.end())
            // {
            //     dp[i] = true;
            //     continue;
            // }
            for (int j = 0; j < i; j++)
            {
                if (dp[j])
                {
                    string word = s.substr(j, i - j);
                    if (table.find(word) != table.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

#endif //ALGORITHM_WORDBREAK_H