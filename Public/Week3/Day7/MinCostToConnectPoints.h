//
// Created by wcx on 2026/3/15.
//

#ifndef ALGORITHM_MINCOSTTOCONNECTPOINTS_H
#define ALGORITHM_MINCOSTTOCONNECTPOINTS_H
#include <algorithm>
#include <complex>

using namespace std;

#include "../../../Solution.h"

class MinCostToConnectPoints: Solution
{
public:
    struct Edge
    {
        int u;
        int v;
        int w;
    };


    int distance(vector<int>& a, vector<int>& b)
    {
        return abs((a[0] - b[0])) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        int n = points.size();
        init(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                edges.emplace_back(Edge{i, j, distance(points[i], points[j])});
            }
        }

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
        {
            return a.w < b.w;
        });

        int count = 0;
        int min_cost = 0;
        for (const auto& edge: edges)
        {
            if (isConnected(edge.u, edge.v)) { continue; }
            unite(edge.u, edge.v);
            min_cost += edge.w;
            count++;
            if (count == n - 1) { break; }
        }
        return min_cost;
    }

    void init(int n)
    {
        parent.resize(n);
        size_.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size_[i] = 1;
        }
    }

    int find(int x)
    {
        if (parent[x] == x) { return x; }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (size_[rootx] <= size_[rooty])
        {
            size_[rooty] += size_[rootx];
            parent[rootx] = rooty;
        }
        else
        {
            size_[rootx] += size_[rooty];
            parent[rooty] = rootx;
        }

    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }

    vector<int> parent;
    vector<int> size_;

};

#endif //ALGORITHM_MINCOSTTOCONNECTPOINTS_H