//
// Created by wcx on 2026/3/18.
//

#ifndef ALGORITHM_MEDIANFINDER_H
#define ALGORITHM_MEDIANFINDER_H
#include <deque>

#include "../../../Solution.h"

using namespace std;

class MedianFinder: Solution {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (nums.empty())
        {
            nums.push_back(num);
            return;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (num < nums[mid])
            {
                right = mid;
            }
            else if (num > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                nums.insert(nums.begin() + mid, num);
                return;
            }
        }
        if (num < nums[left])
        {
            nums.insert(nums.begin() + left, num);
        }
        else
        {
            nums.insert(nums.begin() + left + 1, num);
        }


    }

    double findMedian() {
        int mid = nums.size() / 2;
        return nums.size() % 2 == 0 ? ((double)nums[mid - 1] + nums[mid]) / 2 : nums[mid];
    }

    deque<int> nums;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#endif //ALGORITHM_MEDIANFINDER_H