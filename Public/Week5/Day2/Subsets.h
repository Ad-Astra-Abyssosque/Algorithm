//
// Created by wcx on 2026/3/24.
//

#ifndef ALGORITHM_SUBSETS_H
#define ALGORITHM_SUBSETS_H
#include "../../../Solution.h"
using namespace std;

class Subsets: public Solution
{
public:
    vector<bool> chosen;
    vector<int> path;
    vector<vector<int>> ans;
    int subset_len = 0;

    vector<vector<int>> subsets(vector<int>& nums) {
        chosen.resize(nums.size(), false);
        for (subset_len = 0; subset_len <= nums.size(); subset_len++)
        {
            work(nums);
            path.clear();
            // chosen.assign(nums.size(), false);
        }
        return ans;
    }

    void work(vector<int>& nums)
    {
        if (path.size() == subset_len)
        {
            ans.push_back(path);

            return;
        }
        vector<int> restore;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!chosen[i])
            {
                chosen[i] = true;
                path.push_back(nums[i]);
                work(nums);
                path.pop_back();
                restore.push_back(i);
            }
        }
        for (int i: restore) { chosen[i] = false; }
    }

    virtual void main() override
    {
        vector<int> nums = {1};
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

#endif //ALGORITHM_SUBSETS_H