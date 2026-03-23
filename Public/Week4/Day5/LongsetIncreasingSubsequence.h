//
// Created by wcx on 2026/3/20.
//

#ifndef ALGORITHM_LONGSETINCREASINGSUBSEQUENCE_H
#define ALGORITHM_LONGSETINCREASINGSUBSEQUENCE_H
#include <set>

#include "../../../Solution.h"
using namespace std;

class LongsetIncreasingSubsequence: Solution
{
public:
    struct Cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first < b.first;
        }
    };

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        // first: num, second: index in dp
        set<pair<int, int>, Cmp> s;

        int max_len = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_len = max(dp[i], max_len);
                }
            }
        }
        return max_len;
    }

    virtual void main() override
    {
        vector<int> nums{10,9,2,5,3,7,101,18};
        std::cout << lengthOfLIS(nums) << std::endl;
    }
};

#endif //ALGORITHM_LONGSETINCREASINGSUBSEQUENCE_H