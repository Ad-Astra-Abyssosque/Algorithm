//
// Created by wcx on 2026/2/26.
//

#ifndef ALGORITHM_NONOVERLAPPINGINTERVALS_H
#define ALGORITHM_NONOVERLAPPINGINTERVALS_H
#include <algorithm>
#include <vector>
#include <iostream>

#include "../../../Solution.h"

class NonOverlappingIntervals: public Solution
{
public:

    int eraseOverlapIntervals_Dynamic(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b)
            {
                return a[0] < b[0];
            });
        // for (int i = 0; i < intervals.size(); i++)
        // {
        //     std::cout << "{" << intervals[i][0] << ", " << intervals[i][1] << "}, ";
        // }
        // std::cout << std::endl;
        std::vector<int> f = std::vector<int>(intervals.size(), 1);
        for (int i = 1; i < intervals.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[j][1] < intervals[i][0])
                {
                    f[i] = std::max(f[i], f[j] + 1);
                }
            }
        }
        auto it = std::max_element(f.begin(), f.end());
        return intervals.size() - *it;
    }

    int eraseOverlapIntervals_Greedy(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b)
            {
                return a[1] < b[1];
            });
        int pre = 0;
        int len = 1;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= intervals[pre][1])
            {
                pre = i;
                len++;
            }
        }
        return intervals.size() - len;
    }

    virtual void main() override
    {
        std::vector<std::vector<int>> intervals = {{-3035,30075},{1937,6906},{11834,20971},{44578,45600},{28565,37578},{19621,34415},{32985,36313},{-8144,1080},{-15279,21851},{-27140,-14703},{-12098,16264},{-36057,-16287},{47939,48626},{-15129,-5773},{10508,46685},{-35323,-26257}};
        std::cout << eraseOverlapIntervals_Dynamic(intervals) << std::endl;
    }
};

#endif //ALGORITHM_NONOVERLAPPINGINTERVALS_H