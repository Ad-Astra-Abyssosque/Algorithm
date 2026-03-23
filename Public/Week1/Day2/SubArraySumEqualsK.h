//
// Created by wcx on 2026/2/2.
//

#ifndef ALGORITHM_SUBARRAYSUM_H
#define ALGORITHM_SUBARRAYSUM_H

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

#include "../../../Solution.h"

using namespace std;

class SubArraySumEqualsK: public Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        // 计算前缀和
        unordered_map<int, int> map;
        vector<int> pre = vector<int>(nums.size(), 0);
        int result = 0;

        // 对于给定i，我们知道前缀和 pre[i] = sum(0, i)，以及i之前的所有前缀和
        // 想要知道有多少末尾元素为i的子串的和为k
        // 就相当于要求：i之前有多少前缀和为 pre[i] - k
        // 因为 pre[j] + k = pre[i]

        // 因此我们维护一个map，key为前缀和，value为前缀和为key的子串（0，i-1）的个数
        // 也就是 map 必须只包含 下标 < i 的前缀和计数
        // map 的语义必须是：统计所有 j ∈ [0..i-1] 的 pre[j] 次数
        for (int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            pre[i] = sum;
            // 为什么要先在map中查，再把map[sum]更新计数？
            // 因为我们要找的sub array必须为非空
            // 对于k = 0的情况，如果我们先map[sum]++，那么我们获取map[pre-k]的时候就相当于把[0,i] + []的情况也加到最后结果中了
            if (pre[i] == k) { result++; }
            int target = pre[i] - k;
            if (map.find(target) != map.end()) {
                result += map[target];
            }
            // 更新sum(0,i)的计数
            if (map.find(sum) != map.end()) {
                map[sum]++;
            }
            else {
                map[sum] = 1;
            }
        }

        // 如果等算完pre再从头找就不对了
        // 因为此时map中已经存的不是i之前的数量，而是整个数组中前缀和为各个值的数量
        // 因此统计count的过程必须要放在计算前缀和的流程中
        // for (int i = 0; i < pre.size(); i++) {
        //     if (pre[i] == k) { result++; }
        //     int target = pre[i] - k;
        //     if (map.find(target) != map.end()) {
        //         result += map[target];
        //     }
        // }

        return result;
    }

    int subarraySum_2thTry(vector<int>& nums, int k) {
        int pre = 0;
        int result = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            int target = pre - k;
            if (map.find(target) != map.end()) {
                result += map[target];
            }
            map[pre]++;
        }
        return result;
    }


    virtual void main() override {
        vector<int> nums = {1, 1, 1};
        int res = subarraySum_2thTry(nums, 2);
        std::cout << res << std::endl;
    }
};

#endif //ALGORITHM_SUBARRAYSUM_H