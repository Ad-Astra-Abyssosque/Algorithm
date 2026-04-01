//
// Created by User on 2026/4/1.
//

#ifndef ALGORITHM_INSERTSORT_H
#define ALGORITHM_INSERTSORT_H

#include "../../Solution.h"
using namespace std;

class InsertSort: public Solution {

public:
    void insertionSort(vector<int>& nums) {
        // 7 6 5 4 3 2 1
        // 6 7 5 4 3 2 1

        for (int i = 1; i < nums.size(); i++) {
            int target = i - 1;
            for (int j = i; j > 0 && nums[j] < nums[target]; j--) {
                swap(nums[j], nums[target]);
                target--;
            }
        }
    }

    virtual void main() override {
        vector<int> nums = {5, 2, 4, 6, 1, 3};
        insertionSort(nums);
        for (int& num: nums) {
            cout << num << " ";
        }
    }
};

#endif //ALGORITHM_INSERTSORT_H
