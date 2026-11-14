//
// Created by yoimiya on 2026/11/14.
//

#ifndef ALGORITHM_ROTATEARRAY_H
#define ALGORITHM_ROTATEARRAY_H
#include <numeric>

#include "../../../Solution.h"

using namespace std;

class RotateArray: public Solution {
public:
    int n;

    void rotate(vector<int>& nums, int k) {
        n = nums.size();
        if (k == 0) { return; }

        int x = gcd(n, k);
        for (int i = 0; i < x; i++) {
            work(nums, k, i, n / x);
        }
    }

    void work(vector<int>& nums, int k, int start, int times) {
        int cur = start;
        int numToFill = nums[cur];
        for (int i = 0; i < times; i++) {
            int next = (cur + k) % n;
            int tmp = nums[next];
            nums[next] = numToFill;

            numToFill = tmp;
            cur = next;
        }
    }
};

#endif //ALGORITHM_ROTATEARRAY_H
