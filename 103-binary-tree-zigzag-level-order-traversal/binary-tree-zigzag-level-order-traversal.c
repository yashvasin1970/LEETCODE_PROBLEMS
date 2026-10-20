
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize,
                       int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (root == NULL)
        return NULL;

    int capacity = 2000;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    struct TreeNode** queue = malloc(capacity * sizeof(struct TreeNode*));

    int front = 0, rear = 0;
    int leftToRight = 1;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int* level = malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            int index = leftToRight ? i : levelSize - 1 - i;
            level[index] = node->val;

            if (node->left != NULL)
                queue[rear++] = node->left;

            if (node->right != NULL)
                queue[rear++] = node->right;
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;

        leftToRight = !leftToRight;
    }

    free(queue);
    return result;
}
