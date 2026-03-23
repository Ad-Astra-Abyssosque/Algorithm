//
// Created by wcx on 2026/3/13.
//

#ifndef ALGORITHM_COURSESCHEDULE_H
#define ALGORITHM_COURSESCHEDULE_H

#include <algorithm>
#include <queue>
#include <vector>

#include "../../../Solution.h"

using namespace std;

class CourseSchedule: Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 邻接表
        vector<vector<int>> graph(numCourses, vector<int>());
        // 入度表
        vector<int> inDegrees(numCourses, 0);
        queue<int> q;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int target = prerequisites[i][0];
            int pre = prerequisites[i][1];
            // need study pre before study target
            // pre -> target
            graph[pre].emplace_back(target);
            inDegrees[target]++;
        }

        for (int i = 0; i < inDegrees.size(); i++)
        {
            if (inDegrees[i] == 0) { q.push(i);}
        }

        while (!q.empty())
        {
            int idx = q.front();
            q.pop();
            // 删除从该点出发的所有边，对应点的入读-1
            for (int i = 0; i < graph[idx].size(); i++)
            {
                int course = graph[idx][i];
                inDegrees[course]--;
                if (inDegrees[course] == 0)
                {
                    q.push(course);
                }
            }
            graph[idx].clear();
            // 该课程无冲突
            numCourses--;
        }

        return numCourses == 0;
    }

    virtual void main() override
    {
        vector<vector<int>> pre= {{1, 0}};
        canFinish(2, pre);
    }
};

#endif //ALGORITHM_COURSESCHEDULE_H