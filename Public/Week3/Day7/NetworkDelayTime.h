//
// Created by wcx on 2026/3/15.
//

#ifndef ALGORITHM_NETWORKDELAYTIME_H
#define ALGORITHM_NETWORKDELAYTIME_H
#include <queue>

#include "../../../Solution.h"

using namespace std;

class NetworkDelayTime: Solution
{
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<std::pair<int, int>>> graph(n, vector<std::pair<int, int>>());
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        for (auto& edge: times)
        {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int w = edge[2];
            graph[u].emplace_back(v, w);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k - 1);
        dist[k - 1] = 0;
        while (!pq.empty())
        {
            auto [curDist, u] = pq.top();
            pq.pop();
            if (visited[u]) { continue; }

            visited[u] = true;
            for (auto edge: graph[u])
            {
                int v = edge.first;
                int w = edge.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int max_dist = 0;
        for (int d: dist)
        {
            max_dist = max(d, max_dist);
        }
        return max_dist == INT_MAX ? -1 : max_dist;
    }
};

#endif //ALGORITHM_NETWORKDELAYTIME_H