//
// Created by wcx on 2026/3/24.
//

#ifndef ALGORITHM_PERMUTATIONS_BETTER_H
#define ALGORITHM_PERMUTATIONS_BETTER_H
#include "../../../Solution.h"
using namespace std;

class Permutations_Better: public Solution
{
public:
    vector<bool> choosen;
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums)
    {
        choosen.resize(nums.size(), false);
        work(nums);
        return ans;
    }

    void work(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!choosen[i])
            {
                choosen[i] = true;
                path.push_back(nums[i]);
                work(nums);
                path.pop_back();
                choosen[i] = false;
            }
        }
    }

    virtual void main() override
    {
        vector<int> nums = {1, 2, 3};
        auto res = permute(nums);
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

#endif //ALGORITHM_PERMUTATIONS_BETTER_H