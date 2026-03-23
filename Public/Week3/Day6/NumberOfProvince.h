//
// Created by wcx on 2026/3/14.
//

#ifndef ALGORITHM_NUMBEROFPROVINCE_H
#define ALGORITHM_NUMBEROFPROVINCE_H

#include <queue>
#include <vector>

using namespace std;

class NumberOfProvince
{
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> edges(isConnected.size(), vector<int>());
        int m = isConnected.size();
        int n = isConnected[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (j != i && isConnected[i][j])
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        vector<int> states(n, 0);
        queue<int> q;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (states[i]) { continue; }
            q.push(i);
            while (!q.empty())
            {
                int province = q.front();
                states[province] = 1;
                q.pop();
                for (int j = 0; j < edges[province].size(); j++)
                {
                    if (states[edges[province][j]] == 0) { q.push(edges[province][j]); }
                }
            }
            count++;
        }
        return count;
    }
};

#endif //ALGORITHM_NUMBEROFPROVINCE_H