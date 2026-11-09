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
    /**
     * 自底向上 DP
     */
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, int> table;
        for (const string &word: wordDict) {
            table[word] = 1;
        }
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            // if (table.find(s.substr(0, i)) != table.end())
            // {
            //     dp[i] = true;
            //     continue;
            // }
            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (table.find(word) != table.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }

    /**
     * 记忆化DFS
     */
    unordered_map<string, bool> table;

    bool wordBreak2(string s, vector<string>& wordDict) {

        for (string& word: wordDict) {
            table[word] = true;
        }

        return check(s, 0);
    }

    bool check(const string& s, int start) {
        for (int i = start; i < s.length(); i++) {
            string word = s.substr(start, i - start + 1);
            if (table.find(word) != table.end()) {
                bool success = check(s, start + word.length());
                if (success) { return true;}
            }
        }
        return false;
    }
};

#endif //ALGORITHM_WORDBREAK_H