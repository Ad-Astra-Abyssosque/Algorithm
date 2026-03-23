//
// Created by wcx on 2026/2/5.
//

#ifndef ALGORITHM_TRAPPINGRAINWATER_H
#define ALGORITHM_TRAPPINGRAINWATER_H

#include <iostream>
#include <vector>

#include "../../../Solution.h"
using namespace std;

class TrappingRainWater: public Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int start = 0, end = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (start <= end) {
            leftMax = max(height[start], leftMax);
            rightMax = max(height[end], rightMax);

            if (height[start] < height[end]) {
                result += leftMax - height[start];
                start++;
            }
            else {
                result += rightMax - height[end];
                end--;
            }
        }
        return result;
    }

    // 更符合直觉
    // 解释看下面
    int trap2(vector<int>& height) {
        int result = 0;
        int start = 0, end = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (start <= end) {
            leftMax = max(height[start], leftMax);
            rightMax = max(height[end], rightMax);

            if (leftMax < rightMax) {
                result += leftMax - height[start];
                start++;
            }
            else {
                result += rightMax - height[end];
                end--;
            }
        }
        return result;
    }

    int trap_2thTry(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int leftMax = height[start];
        int rightMax = height[end];
        int rain = 0;
        while (start < end) {
            if (height[start] < height[end]) {
                leftMax = max(leftMax, height[start]);
                rain += leftMax - height[start];
                start++;
            }
            else {
                rightMax = max(rightMax, height[end]);
                rain += rightMax - height[end];
                end--;
            }
        }
        return rain;
    }


    virtual void main() override {
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        cout << trap_2thTry(height) << endl;
    }
};

#endif //ALGORITHM_TRAPPINGRAINWATER_H