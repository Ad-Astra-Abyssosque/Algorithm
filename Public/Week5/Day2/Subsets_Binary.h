//
// Created by wcx on 2026/3/24.
//

#ifndef ALGORITHM_SUBSETS_BINARY_H
#define ALGORITHM_SUBSETS_BINARY_H
#include <cmath>

#include "../../../Solution.h"
using namespace std;

class Subsets_Binary: public Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = pow(2, nums.size()) - 1;
        for (int i = 0; i <= len; i++)
        {
            vector<int> sub_ans;
            for (int j = 0, mask = i; j < nums.size(); j++, mask = mask >> 1)
            {
                int flag = mask & 1;
                if (flag == 1)
                {
                    sub_ans.push_back(nums[j]);
                }
            }
            ans.push_back(std::move(sub_ans));
        }
        return ans;
    }

    virtual void main() override
    {
        vector<int> nums = {1,2,3};
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

#endif //ALGORITHM_SUBSETS_BINARY_H