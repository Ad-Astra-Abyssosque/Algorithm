//
// Created by wcx on 2026/2/7.
//

#ifndef ALGORITHM_FINDFIRSTANDLAST_H
#define ALGORITHM_FINDFIRSTANDLAST_H

#include <iostream>
#include <vector>

#include "../../../Solution.h"

class FindFirstAndLast: public Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        // lower_bound
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else if (nums[mid] >= target) {
                if (l == r) break;
                r = mid;
            }
        }

        if (target != nums[mid]) {
            return {-1, -1};
        }
        int start = mid;
        // upper_bound
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                if (l == r) break;
                r = mid;
            }
        }
        int end = mid - 1;
        return {start, end};
    }

    virtual void main() override {
        std::vector<int> nums = {5,7,7,8,8,10};
        auto res = searchRange(nums, 8);
        for (auto i : res) {
            std::cout << i << " ";
        }
    }
};

#endif //ALGORITHM_FINDFIRSTANDLAST_H