//
// Created by wcx on 2026/2/13.
//

#ifndef ALGORITHM_FINDKTHLARGEST_H
#define ALGORITHM_FINDKTHLARGEST_H

#include <iostream>
#include <vector>

#include "../../../Solution.h"
#include <queue>

using namespace std;

class FindKthLargeset: Solution
{
public:

    int findKthLargest(vector<int>& nums, int k) {
        quicksort(nums, 0, nums.size() -1, nums.size() - k);
        return nums[nums.size() - k];
    }

    void quicksort(vector<int>& nums, int left, int right, const int& k) {
        if (left >= right) { return; }
        int pos = partition_dig(nums, left, right);

        if (k < pos) { quicksort(nums, left, pos - 1, k); }
        else if (k > pos) { quicksort(nums, pos + 1, right, k); }
    }

    int partition_hoare(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int i = left - 1;
        int j = right + 1;
        while (i < j) {
            do { i++; } while(nums[i] < pivot);
            do { j--; } while(nums[j] > pivot);
            if (i < j) { swap(nums[i], nums[j]); }
        }
        return j;
    }

    int partition_dig(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int i = left - 1;
        int j = right + 1;
        while (i != j) {
            do { j--; } while(nums[j] > pivot);
            swap(nums[j], nums[i]);
            do  { i++; } while(nums[i] < pivot);
            swap(nums[j], nums[i]);
        }
        nums[j] = pivot;
        return j;
    }

    virtual void main() override
    {
        std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
        findKthLargest(nums, 4);
        for (int x : nums) std::cout << x << " ";
        std::cout << "\n";
    }
};

#endif //ALGORITHM_FINDKTHLARGEST_H