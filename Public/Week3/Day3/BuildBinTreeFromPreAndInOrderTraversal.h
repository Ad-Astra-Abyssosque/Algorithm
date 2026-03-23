//
// Created by wcx on 2026/3/4.
//

#ifndef ALGORITHM_BUILDBINTREEFROMPREANDINORDERTRAVERSAL_H
#define ALGORITHM_BUILDBINTREEFROMPREANDINORDERTRAVERSAL_H

#include <unordered_map>
#include <vector>
#include "../TreeNode.h"

class BuildBinTreeFromPreAndInOrderTraversal
{
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            hashmap[inorder[i]] = i;
        }
        return work(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* work(std::vector<int>& preorder, std::vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left >= pre_right) return nullptr;

        int root_value = preorder[pre_left];
        int root_index_inorder = hashmap[root_value];
        int left_length = root_index_inorder - in_left;
        TreeNode* root = new TreeNode(root_value);
        root->left = work(preorder, inorder, pre_left + 1, pre_left + left_length, in_left, root_index_inorder - 1);
        root->right = work(preorder, inorder, pre_left + left_length + 1, pre_right, root_index_inorder + 1, in_right);

        return root;
    }


    std::unordered_map<int, int> hashmap;
};

#endif //ALGORITHM_BUILDBINTREEFROMPREANDINORDERTRAVERSAL_H