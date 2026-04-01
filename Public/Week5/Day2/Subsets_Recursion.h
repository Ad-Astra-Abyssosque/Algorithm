//
// Created by wcx on 2026/3/24.
//

#ifndef ALGORITHM_SUBSETS_RECURSION_H
#define ALGORITHM_SUBSETS_RECURSION_H
#include "../../../Solution.h"
using namespace std;

class Subsets_Recursion: public Solution
{
public:

    vector<int> solution;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        work(nums, 0);
        return ans;
    }

    void work(vector<int>& nums, int cur)
    {
        if (cur == nums.size())
        {
            ans.push_back(solution);
            // ans.push_back(std::move(solution));
            return;
        }

        solution.push_back(nums[cur]);
        work(nums, cur + 1);
        solution.pop_back();

        work(nums, cur + 1);
    }

    virtual void main() override
    {
        vector<int> nums = {1, 2, 3};
        auto res = subsets(nums);
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif //ALGORITHM_SUBSETS_RECURSION_H