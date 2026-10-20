
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int targetSum, int* path, int depth,
         int*** result, int* returnSize, int** returnColumnSizes) {
    if (root == NULL)
        return;

    path[depth] = root->val;
    targetSum -= root->val;

    if (root->left == NULL && root->right == NULL && targetSum == 0) {
        *result = realloc(*result, (*returnSize + 1) * sizeof(int*));
        *returnColumnSizes = realloc(*returnColumnSizes,
                                     (*returnSize + 1) * sizeof(int));

        int* copy = malloc((depth + 1) * sizeof(int));
        for (int i = 0; i <= depth; i++)
            copy[i] = path[i];

        (*result)[*returnSize] = copy;
        (*returnColumnSizes)[*returnSize] = depth + 1;
        (*returnSize)++;
        return;
    }

    dfs(root->left, targetSum, path, depth + 1,
        result, returnSize, returnColumnSizes);
    dfs(root->right, targetSum, path, depth + 1,
        result, returnSize, returnColumnSizes);
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize,
              int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;

    int** result = NULL;
    int path[5000];

    dfs(root, targetSum, path, 0,
        &result, returnSize, returnColumnSizes);

    return result;
}
