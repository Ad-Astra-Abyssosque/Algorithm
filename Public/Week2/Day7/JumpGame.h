//
// Created by wcx on 2026/2/27.
//

#ifndef ALGORITHM_JUMPGAME_H
#define ALGORITHM_JUMPGAME_H
#include <set>
#include <vector>

#include "../../../Solution.h"

class JumpGame: public Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        if (nums.size() == 1) {return true;}
        std::set<int> middle;
        middle.insert(0);
        int last = nums.size() - 1;
        while (!middle.empty())
        {
            int cursor = *middle.begin();
            middle.erase(middle.begin());
            for (int i = 1; i <= nums[cursor]; i++)
            {
                int next = cursor + i;
                if (next == last) { return true; }
                if (next < last) { middle.insert(next); }
            }
        }
        return false;
    }

    bool canJump_Greedy(std::vector<int>& nums)
    {
        // if (nums.size() == 1) {return true;}
        int last = nums.size() - 1;
        for (int i = 0, end = nums[0]; i < end; i++)
        {
            end = std::max(end, i + nums[i]);
            if (end >= last) { return true; }
        }
        return false;
    }

    void main() override
    {
        std::vector<int> nums = {0};
        std::cout << canJump(nums) << std::endl;
    }
};

#endif //ALGORITHM_JUMPGAME_H