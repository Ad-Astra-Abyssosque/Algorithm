//
// Created by wcx on 2026/3/26.
//

#ifndef ALGORITHM_MAXIMUMSUBARRAY_H
#define ALGORITHM_MAXIMUMSUBARRAY_H
#include "../../../Solution.h"

using namespace std;

class MaximumSubarray: public Solution
{
public:
    int maxSubarray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        int max_sum = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            max_sum = max(max_sum, dp[i]);
        }

        return max_sum;


    }
};

#endif //ALGORITHM_MAXIMUMSUBARRAY_H