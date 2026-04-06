//
// Created by wcx on 2026/4/4.
//

#ifndef ALGORITHM_SINGLENUMBER_H
#define ALGORITHM_SINGLENUMBER_H
#include "../../../Solution.h"

using namespace std;

class SingleNumber: public Solution
{
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int& num: nums)
        {
            x  = x ^ num;
        }
        return x;
    }
};

#endif //ALGORITHM_SINGLENUMBER_H