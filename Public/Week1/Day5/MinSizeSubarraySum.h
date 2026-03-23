//
// Created by wcx on 2026/2/6.
//

#ifndef ALGORITHM_MINSIZESUBARRAYSUM_H
#define ALGORITHM_MINSIZESUBARRAYSUM_H

#include <iostream>
#include <ostream>
#include <vector>

#include "../../../Solution.h"

class MinSizeSubarraySum: public Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int result = 0;
        int windowLength = 0;
        int start = 0, end = -1;
        int sum = 0;
        while (start < nums.size() && end < nums.size()) {
            if (sum >= target) {
                result = result == 0 ? windowLength : std::min(windowLength, result);
                sum -= nums[start];
                windowLength--;
                start++;
            }
            else {
                end++;
                if (end == nums.size()) {
                    break;
                }
                sum += nums[end];
                windowLength++;

            }
        }
        return result;
    }

    virtual void main() override {
        std::vector nums = {2,3,1,2,4,3};
        std::cout << minSubArrayLen(7, nums) << std::endl;
    }
};

#endif //ALGORITHM_MINSIZESUBARRAYSUM_H