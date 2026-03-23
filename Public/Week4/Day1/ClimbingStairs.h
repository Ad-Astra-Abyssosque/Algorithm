//
// Created by wcx on 2026/3/16.
//

#ifndef ALGORITHM_CLIMBINGSTAIRS_H
#define ALGORITHM_CLIMBINGSTAIRS_H
#include "../../../Solution.h"

class ClimbingStairs: Solution
{
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        if (n >= 1) { dp[1] = 1; }

        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        int pre_step1 = 1;
        int pre_step2 = 1;
        int cur = 0;
        for (int i = 2; i < n + 1; i++)
        {
            pre_step2 = pre_step1;
            pre_step1 = cur;
            cur = pre_step1 + pre_step2;
        }
        return cur;
    }
};

#endif //ALGORITHM_CLIMBINGSTAIRS_H