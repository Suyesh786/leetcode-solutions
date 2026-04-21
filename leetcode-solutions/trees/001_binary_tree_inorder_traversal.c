#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void dfs(struct TreeNode* node, int* result, int* returnSize) {
    if(node == NULL) return;

    dfs(node->left, result, returnSize);
    result[(*returnSize)++] = node->val;
    dfs(node->right, result, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));
    *returnSize = 0;

    dfs(root, result, returnSize);
    return result;
}