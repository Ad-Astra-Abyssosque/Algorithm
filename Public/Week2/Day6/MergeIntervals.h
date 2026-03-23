//
// Created by wcx on 2026/2/26.
//

#ifndef ALGORITHM_MERGEINTERVALS_H
#define ALGORITHM_MERGEINTERVALS_H
#include <algorithm>
#include <vector>

class MergeIntervals
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b)
            {
                return a[0] < b[0];
            });

        if (intervals.size() == 1) { return intervals; }
        std::vector<std::vector<int>> result;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= intervals[i - 1][1])
            {
                intervals[i][0] = std::min(intervals[i - 1][0], intervals[i][0]);
                intervals[i][1] = std::max(intervals[i - 1][1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i - 1]);
            }
        }
        result.push_back(intervals[intervals.size() - 1]);
        return result;
    }
};

#endif //ALGORITHM_MERGEINTERVALS_H