
#include <stdbool.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkBST(struct TreeNode* root, long long min, long long max) {
    if (root == NULL)
        return true;

    if (root->val <= min || root->val >= max)
        return false;

    return checkBST(root->left, min, root->val) &&
           checkBST(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return checkBST(root, LLONG_MIN, LLONG_MAX);
}
