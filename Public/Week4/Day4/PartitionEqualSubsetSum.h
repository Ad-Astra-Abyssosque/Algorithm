//
// Created by wcx on 2026/3/19.
//

#ifndef ALGORITHM_PARTITIONEQUALSUBSETSUM_H
#define ALGORITHM_PARTITIONEQUALSUBSETSUM_H
#include <unordered_map>

#include "../../../Solution.h"

using namespace std;

class PartitionEqualSubsetSum: Solution
{
public:
    bool canPartition(vector<int>& nums) {

        unordered_map<int, int> map;
        int sum = 0;
        for (int& num: nums)
        {
            map[num]++;
            sum += num;
        }

        if (sum % 2 != 0) { return false; }
        int half = sum / 2;
        vector<int> dp(half + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = half; j >= nums[i]; j--)
            {
                if (j - nums[i] >= 0 && dp[j - nums[i]] != -1)
                dp[j] = dp[j - nums[i]] + 1;
            }
        }
        return dp[half] != -1;
    }
};

#endif //ALGORITHM_PARTITIONEQUALSUBSETSUM_H