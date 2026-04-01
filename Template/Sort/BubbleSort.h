//
// Created by User on 2026/4/1.
//

#ifndef ALGORITHM_BUBBLESORT_H
#define ALGORITHM_BUBBLESORT_H

#include "../../Solution.h"
using namespace std;

class BubbleSort: public Solution {
public:
    void bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1- i; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    virtual void main() override {
        vector<int> nums = {5, 2, 4, 6, 1, 3};
        bubbleSort(nums);
        for (int& num: nums) {
            cout << num << " ";
        }
    }
};

#endif //ALGORITHM_BUBBLESORT_H
