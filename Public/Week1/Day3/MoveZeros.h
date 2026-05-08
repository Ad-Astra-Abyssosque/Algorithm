//
// Created by wcx on 2026/2/3.
//

#ifndef ALGORITHM_MOVEZEROS_H
#define ALGORITHM_MOVEZEROS_H
#include <iostream>
#include <ostream>
#include <vector>

#include "../../../Solution.h"

class MoveZeros: public Solution {
public:
    // void moveZeroes(std::vector<int>& nums) {
    //     int count = 0;
    //     int head = 0;
    //     for (int scan = 0; head < nums.size() && scan < nums.size();) {
    //         if (nums[scan] != 0) {
    //             nums[head] = nums[scan];
    //             head++;
    //             scan++;
    //         }
    //         else {
    //             count++;
    //             scan++;
    //
    //         }
    //     }
    //
    //     for (int i = 0; i < count; i++) {
    //         nums[i + head] = 0;
    //     }
    // }

    void moveZeroes(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        do {
            while (slow < nums.size() && nums[slow] != 0) { slow++; }
            fast = slow + 1;
            while (fast < nums.size() && nums[fast] == 0) { fast++; }
            if (fast < nums.size()) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        } while (slow < nums.size() && fast < nums.size());
    }

    virtual void main() override {
        std::vector<int> nums = {0,1,0,3,12};
        moveZeroes(nums);
        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i] << std::endl;
        }
    }
};


#endif //ALGORITHM_MOVEZEROS_H