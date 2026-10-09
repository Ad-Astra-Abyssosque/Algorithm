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
        return dp(root, true);
    }

    int dp(TreeNode* node, bool canRob) {
        if (!node) {
            return 0;
        }

        if (canRob) {
            if (trueMap.find(node) == trueMap.end()) {
                int tmp = max(
                    node->val + dp(node->left, false) + dp(node->right, false),
                    dp(node->left, true) + dp(node->right, true)
                );
                trueMap[node] = tmp;
                return tmp;
            }
            else {
                return trueMap[node];
            }

        }
        else {
            if (falseMap.find(node) == falseMap.end()) {
                int tmp = dp(node->left, true) + dp(node->right, true);
                falseMap[node] = tmp;
                return tmp;
            }
            else {
                return falseMap[node];
            }

        }
    }
};

#endif //ALGORITHM_HOUSEROBBER3_H
