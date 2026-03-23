//
// Created by wcx on 2026/3/14.
//

#ifndef ALGORITHM_REDUNDANTCONNECTIONS_H
#define ALGORITHM_REDUNDANTCONNECTIONS_H

#include "../../../Solution.h"
using namespace std;

class ReduandantConnections: Solution
{
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        initialize(edges.size());
        vector<int> redundant;
        for (auto& edge: edges)
        {
            int from = edge[0] - 1;
            int to = edge[1] - 1;
            if (isConnected(from, to))
            {
                redundant = edge;
                continue;
            }
            unite(from , to);
        }
        return redundant;
    }

    void initialize(int n)
    {
        parent.resize(n);
        rank_.resize(n);
        size_.resize(n);

        // TODO: 初始化 parent 和 rank_
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size_[i] = 1;
        }
    }

    // 查找 x 的根节点
    int find(int x)
    {
        // TODO: 实现路径压缩
        if (parent[x] == x) { return x; }
        else
        {
            return parent[x] = find(parent[x]);
        }
    }

    // 合并 x 和 y 所在的集合
    void unite(int x, int y)
    {
        // TODO: 按秩合并 / 按大小合并
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) return;

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

    // 判断 x 和 y 是否属于同一个集合
    bool isConnected(int x, int y)
    {
        // TODO
        return find(x) == find(y);
    }

    vector<int> parent;
    vector<int> rank_;   // 或者 size，二选一都行
    vector<int> size_;
};

#endif //ALGORITHM_REDUNDANTCONNECTIONS_H