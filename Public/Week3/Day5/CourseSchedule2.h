//
// Created by wcx on 2026/3/13.
//

#ifndef ALGORITHM_COURSESCHEDULE2_H
#define ALGORITHM_COURSESCHEDULE2_H

#include <vector>
#include <stack>

using namespace std;

class CourseSchedule2
{
public:
    enum class State
    {
        Unchecked,
        Checking,
        Checked
    };

    vector<vector<int>> edges;
    vector<State> states;
    stack<int> reversed_order;
    bool isValid = true;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges = vector<vector<int>>(numCourses, vector<int>());
        vector<int> order;
        states = vector<State>(numCourses, State::Unchecked);
        for (auto it: prerequisites)
        {
            int target = it[0];
            int pre = it[1];
            edges[pre].emplace_back(target);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (states[i] == State::Checked) { continue; }
            dfs(i);
            if (!isValid) break;
        }

        if (!isValid) return {};

        while (!reversed_order.empty())
        {
            order.push_back(reversed_order.top());
            reversed_order.pop();
        }
        return order;
    }

    void dfs(int course)
    {
        for (int next: edges[course])
        {
            if (states[next] == State::Unchecked)
            {
                states[next] = State::Checking;
                dfs(next);
                if (!isValid) { return;}
            }
            else if (states[next] == State::Checking)
            {
                isValid = false;
                return;
            }
        }
        states[course] = State::Checked;
        reversed_order.push(course);
    }
};

#endif //ALGORITHM_COURSESCHEDULE2_H