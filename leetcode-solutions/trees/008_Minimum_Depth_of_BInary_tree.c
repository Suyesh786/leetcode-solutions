/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }

    if(root->left != NULL && root->right == NULL){
        //left has a node
        return 1+minDepth(root->left);
    }

    if(root->left == NULL && root->right != NULL){
        //right has a node
        return 1+minDepth(root->right);
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);
    
    return 1 +( (left) > (right) ? right : left );

}