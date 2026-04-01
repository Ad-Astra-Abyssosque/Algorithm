//
// Created by wcx on 2026/3/21.
//

#ifndef ALGORITHM_LONGESTCOMMONSUBSEQUENCE_H
#define ALGORITHM_LONGESTCOMMONSUBSEQUENCE_H
#include "../../../Solution.h"

#include <string>
using namespace std;

class LongestCommonSubsequence: Solution
{
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

#endif //ALGORITHM_LONGESTCOMMONSUBSEQUENCE_H