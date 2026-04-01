//
// Created by wcx on 2026/3/27.
//

#ifndef ALGORITHM_EDITDISTANCE_H
#define ALGORITHM_EDITDISTANCE_H
#include "../../../Solution.h"
#include <string>

using namespace std;


class EditDistance: public Solution
{
public:
    int editDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        if (m == 0) { return n;}
        if (n == 0) { return m;}
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1]});
                }
                else
                {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[m][n];
        // for (int i = 0; i <= m; i++)
        // {
        //     for (int j = 0; j <= n; j++)
        //     {
        //         std::cout << dp[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }


        return 0;
    }

    virtual void main() override
    {
        string word1 = "intention";
        string world2 = "execution";
        editDistance(word1, world2);

    }
};

#endif //ALGORITHM_EDITDISTANCE_H