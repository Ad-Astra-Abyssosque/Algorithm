//
// Created by wcx on 2026/3/30.
//

#ifndef ALGORITHM_COMBINATIONSUM_H
#define ALGORITHM_COMBINATIONSUM_H

#include "../../../Solution.h"

using namespace std;

class CombinationSum: public Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);

        for (int i = 0; i < candidates.size(); i++)
        {
            for (int j = 1; j <= target; j++)
            {
                if (j - candidates[i] < 0) continue;
                vector<vector<int>> arrays = dp[j - candidates[i]];
                if (j - candidates[i] == 0)
                {
                    arrays.push_back({candidates[i]});
                }
                else if (!arrays.empty())
                {
                    for (auto& arr: arrays)
                    {
                        arr.push_back(candidates[i]);
                    }
                }
                dp[j].insert(dp[j].end(), arrays.begin(), arrays.end());
            }
        }
        return dp[target];
    }

    virtual void main() override
    {
        vector<int> nums = {2,3,6,7};
        combinationSum(nums, 7);
    }
};

#endif //ALGORITHM_COMBINATIONSUM_H