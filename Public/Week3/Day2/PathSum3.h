//
// Created by wcx on 2026/3/1.
//

#ifndef ALGORITHM_PATHSUM3_H
#define ALGORITHM_PATHSUM3_H

#include <map>
#include <queue>
#include <stack>

#include "../TreeNode.h"

class PathSum3
{
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        std::map<long long, int> hashmap;
        hashmap[0] = 1;
        dfs(root, targetSum, 0, hashmap);
        return path_count;
    }

    void dfs(TreeNode* node, long long targetSum, long long pre, std::map<long long, int>& hashmap)
    {
        pre += node->val;
        if (hashmap.find(pre - targetSum) != hashmap.end())
        {
            path_count += hashmap[pre - targetSum];
        }
        hashmap[pre]++;
        if (node->left)
        {
            dfs(node->left, targetSum, pre, hashmap);
        }
        if (node->right)
        {
            dfs(node->right, targetSum, pre, hashmap);
        }
        hashmap[pre]--;
        if (hashmap[pre] == 0) { hashmap.erase(pre); }
    }

    int path_count = 0;
};

#endif //ALGORITHM_PATHSUM3_H