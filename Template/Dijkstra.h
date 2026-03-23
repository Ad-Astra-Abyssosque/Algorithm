//
// Created by wcx on 2026/3/15.
//

#ifndef ALGORITHM_DIJKSTRA_H
#define ALGORITHM_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <deque>

#include "../Solution.h"

using namespace std;

class Dijkstra: Solution
{
public:
    // n: 节点个数，编号假设为 0 ~ n-1
    // graph[u] = { {v, w}, ... }，表示 u -> v 的边，权重为 w
    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start)
    {

        // dist[i]：start 到 i 的最短距离
        vector<int> dist(n, INT_MAX);

        // visited[i]：该点的最短距离是否已经确定
        vector<bool> visited(n, false);

        // 小根堆：{当前距离, 节点编号}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // 1. 初始化
        dist[start] = 0;
        pq.emplace(0, start);

        // 2. 主循环
        while (!pq.empty())
        {

            auto [curDist, u] = pq.top();
            pq.pop();

            // 不需要visited的版本：说明这是旧记录，跳过
            // if (curDist > dist[u]) { continue; }
            // 如果该点已经确定最短路，跳过
            if (visited[u]) { continue; }

            // 标记已确定
            visited[u] = true;

            // 遍历邻居并松弛
            for (int i = 0; i < graph[u].size(); i++)
            {

                int v = graph[u][i].first;
                int w = graph[u][i].second;
                // 松弛操作
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist;
    }
};

#endif //ALGORITHM_DIJKSTRA_H