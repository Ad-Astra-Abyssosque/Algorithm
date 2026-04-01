//
// Created by wcx on 2026/3/24.
//

#ifndef ALGORITHM_PERMUTATIONS_H
#define ALGORITHM_PERMUTATIONS_H
#include "../../../Solution.h"
using namespace std;

class Permutations: public Solution
{
public:
    vector<bool> choosen;

    vector<vector<int>> permute(vector<int>& nums)
    {
        choosen.resize(nums.size(), false);
        return work(nums, 0);
    }

    vector<vector<int>> work(const vector<int>& nums, int start)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (choosen[i]) { continue; }
            choosen[i] = true;
            vector<vector<int>> sub_ans = work(nums, i + 1);
            for (vector<int>& sub: sub_ans)
            {
                sub.push_back(nums[i]);
            }
            if (sub_ans.empty())
            {
                sub_ans.push_back({nums[i]});
            }
            choosen[i] = false;
            ans.insert(ans.end(), sub_ans.begin(), sub_ans.end());
        }
        return ans;
    }

    virtual void main() override
    {
        vector<int> nums = {1};
        auto ans = permute(nums);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif //ALGORITHM_PERMUTATIONS_H