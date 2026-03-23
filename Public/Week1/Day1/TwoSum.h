//
// Created by wcx on 2026/2/1.
//

#ifndef ALGORITHM_TWOSUM_H
#define ALGORITHM_TWOSUM_H

#include <unordered_map>
#include <vector>
using namespace std;

class TwoSum {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 对于两个相同的元素，后插入的元素会覆盖掉先插入的元素
        // 而后面的遍历是从头开始的，因此不会遇到自己
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int numToFind = target - nums[i];
            if (map.find(numToFind) != map.end() && map[numToFind] != i) {
                result.push_back(i);
                result.push_back(map[numToFind]);
                break;
            }
        }
        return result;
    }

    /**
     *
     * 对于每一个 x，我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配
     */
    vector<int> twoSum_Better(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};


#endif //ALGORITHM_TWOSUM_H