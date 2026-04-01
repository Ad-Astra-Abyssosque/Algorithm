//
// Created by wcx on 2026/3/30.
//

#ifndef ALGORITHM_COMBINATIONSUM_TRACEBACK_H
#define ALGORITHM_COMBINATIONSUM_TRACEBACK_H
#include "../../../Solution.h"

using namespace std;

class CombinationSum_Traceback: public Solution
{
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> solution;
        work(candidates, solution, 0, target);
        return ans;
    }

    void work(vector<int>& candidates, vector<int>& solution, int idx, int target)
    {
        if (idx == candidates.size()) return;
        if (target == 0)
        {
            ans.push_back(solution);
            return;
        }

        work(candidates, solution, idx + 1, target);

        if (target - candidates[idx] >= 0)
        {
            solution.push_back(candidates[idx]);
            work(candidates, solution, idx, target - candidates[idx]);
            solution.pop_back();
        }

    }
};

#endif //ALGORITHM_COMBINATIONSUM_TRACEBACK_H