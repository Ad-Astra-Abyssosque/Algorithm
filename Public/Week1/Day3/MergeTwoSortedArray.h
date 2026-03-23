//
// Created by wcx on 2026/2/3.
//

#ifndef ALGORITHM_MERGETWOSORTEDARRAY_H
#define ALGORITHM_MERGETWOSORTEDARRAY_H
#include <vector>

class MergeTwoSortedArray {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i1 = m - 1, i2 = n - 1;
        for (int i = nums1.size() - 1; i >= 0; i--) {
            if (i1 < 0) {
                nums1[i] = nums2[i2];
                i2--;
                continue;
            }
            if (i2 < 0) {
                break;
            }
            if (nums1[i1] > nums2[i2]) {
                nums1[i] = nums1[i1];
                i1--;
            }
            else {
                nums1[i] = nums2[i2];
                i2--;
            }

        }
    }
};

#endif //ALGORITHM_MERGETWOSORTEDARRAY_H