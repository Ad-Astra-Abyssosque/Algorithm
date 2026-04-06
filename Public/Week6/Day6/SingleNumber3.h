//
// Created by wcx on 2026/4/6.
//

#ifndef ALGORITHM_SINGLENUMBER3_H
#define ALGORITHM_SINGLENUMBER3_H

#include "../../../Solution.h"

using namespace std;

class SingleNumber3: public Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for (int& num: nums)
        {
            x = x ^ num;
        }
        long long lowest_one_bit = x & -x;
        // cout << lowest_one_bit << endl;
        int a = 0, b = 0;
        for (int& num: nums)
        {
            if ((num & lowest_one_bit) == lowest_one_bit)
            {
                // cout << num << endl;
                a = a ^ num;
            }
            else
            {
                b = b ^ num;
            }
        }
        return {a, b};
    }
};

#endif //ALGORITHM_SINGLENUMBER3_H