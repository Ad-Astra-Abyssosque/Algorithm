//
// Created by wcx on 2026/4/4.
//

#ifndef ALGORITHM_HOUSEROBBER2_H
#define ALGORITHM_HOUSEROBBER2_H
#include "../../../Solution.h"

using namespace std;

class HouseRobber2: public Solution
{
public:

    int work(vector<int>& nums, int start, int end)
    {
        int n = end - start + 1;
        if (n <= 0) { return 0; }
        vector<int> dp(n, 0);
        if (n > 0) { dp[0] = nums[start]; }
        if (n > 1) { dp[1] = max(nums[start], nums[start + 1]); }
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
        }
        return dp[n - 1];
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(work(nums, 0, n - 2), work(nums, 1, n - 1));
        // return max_value;
    }

    virtual void main() override
    {
        vector<int> nums = {200,3,140,20,10};
        cout << rob(nums) << endl;
    }
};

#endif //ALGORITHM_HOUSEROBBER2_H