//
// Created by wcx on 2026/3/14.
//

#ifndef ALGORITHM_MERGEACCOUNTS_H
#define ALGORITHM_MERGEACCOUNTS_H

#include <algorithm>
#include <map>

#include "../../../Solution.h"

using namespace std;

class MergeAccounts: Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> str_id;
        map<string, string> email_name;
        int count = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string str = accounts[i][j];
                if (str_id.find(str) == str_id.end())
                {
                    str_id[str] = count++;
                    email_name[str] = accounts[i][0];
                }
            }
        }
        initialize(count);

        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].size() < 3) { continue; }
            string email1 = accounts[i][1];
            for (int j = 2; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                unite(str_id[email1], str_id[email]);
            }
        }

        map<int, vector<string>> m;
        for (auto& it: str_id)
        {
            int root = find(it.second);
            m[root].emplace_back(it.first);
        }

        vector<vector<string>> answer;
        for (auto& it: m)
        {
            string name = email_name[(it.second)[0]];
            vector<string> tmp = {name};
            std::sort(it.second.begin(), it.second.end());
            tmp.insert(tmp.end(), it.second.begin(), it.second.end());
            answer.emplace_back(std::move(tmp));
        }
        return answer;
    }


    void initialize(int n)
    {
        parent.resize(n);
        rank_.resize(n);
        size_.resize(n);

        // 初始化 parent 和 rank_
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size_[i] = 1;
        }
    }

    // 查找 x 的根节点
    int find(int x)
    {
        // 实现路径压缩
        if (parent[x] == x) { return x; }
        else
        {
            return parent[x] = find(parent[x]);
        }
    }

    // 合并 x 和 y 所在的集合
    void unite(int x, int y)
    {
        // 按大小合并
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
        return find(x) == find(y);
    }

    vector<int> parent;
    vector<int> rank_;   // 或者 size，二选一都行
    vector<int> size_;
};

#endif //ALGORITHM_MERGEACCOUNTS_H