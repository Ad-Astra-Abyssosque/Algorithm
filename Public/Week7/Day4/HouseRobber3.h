//
// Created by yoimiya on 2026/7/21.
//

#ifndef ALGORITHM_HOUSEROBBER3_H
#define ALGORITHM_HOUSEROBBER3_H
#include "../../../Solution.h"
#include "../../Week3/TreeNode.h"

#include <unordered_map>

using namespace std;

class HouseRobber3: public Solution {
public:
    unordered_map<TreeNode*, int> trueMap;
    unordered_map<TreeNode*, int> falseMap;

    int rob(TreeNode* root) {
        return work(root, true);
    }

    int work(TreeNode* node, bool canSteal) {
        if (!node) {
            return 0;
        }

        if (canSteal) {
            if (trueMap.find(node) == trueMap.end()) {
                trueMap[node] = max(
                    node->val + work(node->left, false) + work(node->right, false),
                    work(node->left, true) + work(node->right, true)
                );
            }
            return trueMap[node];
        }
        else {
            if (falseMap.find(node) == falseMap.end()) {
                falseMap[node] = work(node->left, true) + work(node->right, true);
            }
            return falseMap[node];
        }
    }
};

#endif //ALGORITHM_HOUSEROBBER3_H
