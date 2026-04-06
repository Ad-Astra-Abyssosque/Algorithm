//
// Created by wcx on 2026/4/6.
//

#ifndef ALGORITHM_SINGLENUMBER2_H
#define ALGORITHM_SINGLENUMBER2_H

#include "../../../Solution.h"

using namespace std;

class SingleNumber2: public Solution
{
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitsum(32, 0);
        for (int& num: nums) {
            for (int i = 0; i < 32; i++) {
                int bit = (num >> i) & 1;
                bitsum[i] += bit;
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int bit = bitsum[i] % 3;
            ans = ans | (bit << i);
        }
        return ans;
    }
};

#endif //ALGORITHM_SINGLENUMBER2_H