//
// Created by wcx on 2026/2/2.
//

#ifndef ALGORITHM_NUMARRAY_H
#define ALGORITHM_NUMARRAY_H

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

#include "../../../Solution.h"

using namespace std;

class NumArray: public Solution {
public:
    NumArray(vector<int>& nums) {
        _nums = nums;
        int sum = 0;
        _pre.push_back(0);
        // _pre[i]表示的是 从 0 到 i-1的和
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            _pre.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        return _pre[right + 1] - _pre[left];
    }

    virtual void main() override {

    }

private:
    vector<int> _nums;
    vector<int> _pre;
};

#endif //ALGORITHM_NUMARRAY_H