//
// Created by wcx on 2026/2/7.
//

#ifndef ALGORITHM_SEARCHINSERTPOSITION_H
#define ALGORITHM_SEARCHINSERTPOSITION_H

#include <iostream>
#include <ostream>
#include <vector>

#include "../../../Solution.h"

class SearchInsertPosition: public Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int insert = 0;
        while (start <= end) {
            int middle = (start + end) / 2;
            if (nums[middle] == target) { return middle; }
            // 当决定插入的位置时（target不在数组中）
            // 只要是插入到两个元素中间 或 插入到数组末尾，走的都是if语句
            if (target > nums[middle]) {
                start = middle + 1;
                insert = start;
            }
            // 只有插入到数组首部时才走的是else
            // 此时start = 0, end = 1, middle = 0, target < nums[middle]
            else {
                insert = middle;
                end = middle - 1;
            }
        }
        return insert;
    }

    virtual void main() override {
        std::vector<int> nums = {1, 3};
        std::cout << searchInsert(nums, 0) << std::endl;
    }
};

#endif //ALGORITHM_SEARCHINSERTPOSITION_H