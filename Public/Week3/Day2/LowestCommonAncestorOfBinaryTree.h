//
// Created by wcx on 2026/3/1.
//

#ifndef ALGORITHM_LOWESTCOMMONANCESTOROFBINARYTREE_H
#define ALGORITHM_LOWESTCOMMONANCESTOROFBINARYTREE_H

#include "../TreeNode.h"
#include "../../../Solution.h"
#include <map>
#include <queue>

class LowestCommonAncestorOfBinaryTree
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        std::queue<TreeNode*> queue;
        queue.push(root);
        parent[root] = nullptr;
        while (!queue.empty())
        {
            int len = queue.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left)
                {
                    queue.push(node->left);
                    parent[node->left] = node;
                }
                if (node->right)
                {
                    queue.push(node->right);
                    parent[node->right] = node;
                }
            }
        }

        auto p_parent = getParents(p);
        auto q_parent = getParents(q);

        TreeNode* commonAncestor = nullptr;
        for (std::size_t i = p_parent.size(), j = q_parent.size(); i-- > 0 && j-- > 0;)
        {
            if (p_parent[i]->val == q_parent[j]->val)
            {
                commonAncestor = p_parent[i];
            }
        }
        return commonAncestor;
    }

    std::vector<TreeNode*> getParents(TreeNode* node)
    {
        std::vector<TreeNode*> result = {node};
        node = parent[node];
        while (node)
        {
            result.push_back(node);
            node = parent[node];
        }
        return result;
    }

    std::map<TreeNode*, TreeNode*> parent;
};

#endif //ALGORITHM_LOWESTCOMMONANCESTOROFBINARYTREE_H