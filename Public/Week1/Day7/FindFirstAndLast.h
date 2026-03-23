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
        std::vector<int> result;
        // find target first
        int start = 0, end = nums.size() - 1;
        int mid = 0;
        int pos = -1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                pos = mid;
                break;
            }
            if (target > nums[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        if (pos == -1) {
            return {-1, -1};
        }
        // 确定左边界
        start = 0, end = pos;
        int left = 0;
        while (start <= end) {
            mid = (start + end) / 2;
            // 边界在右半边
            if (nums[mid] < target) {
                start = mid + 1;
            }
            // 只能相等，边界在左半边
            else {
                end = mid - 1;
                left = mid;
            }
        }
        // 确定右边界
        start = pos, end = nums.size() - 1;
        int right = nums.size() - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            // 边界在右半边
            if (nums[mid] == target) {
                start = mid + 1;
            }
            // 只能大于target，边界在左半边
            else {
                right = end = mid - 1;
            }
        }

        return {left, right};
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