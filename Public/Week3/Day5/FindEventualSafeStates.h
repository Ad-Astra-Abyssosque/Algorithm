//
// Created by wcx on 2026/3/14.
//

#ifndef ALGORITHM_FINDEVENTUALSAFESTATES_H
#define ALGORITHM_FINDEVENTUALSAFESTATES_H

#include <vector>
#include <stack>

using namespace std;

class FindEventualSafeStates
{
    enum class State
    {
        Unchecked,
        Checking,
        Checked
    };

    vector<vector<int>> edges;
    vector<State> states;
    bool isValid = true;

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        edges = graph;
        vector<int> safe_states;
        states = vector<State>(graph.size(), State::Unchecked);

        for (int i = 0; i < graph.size(); i++)
        {
            isValid = true;
            dfs(i);
            if (isValid)
            {
                safe_states.push_back(i);
            }
        }

        return safe_states;
    }

    void dfs(int course)
    {
        if (states[course] != State::Unchecked)
        {
            isValid = states[course] == State::Checked;
            return;
        }
        states[course] = State::Checking;
        for (int next: edges[course])
        {
            if (states[next] == State::Unchecked)
            {
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
    }
};

#endif //ALGORITHM_FINDEVENTUALSAFESTATES_H