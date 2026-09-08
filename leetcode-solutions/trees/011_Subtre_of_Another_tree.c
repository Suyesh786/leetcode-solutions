/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* root, struct TreeNode* root1){
    if(root == NULL && root1 == NULL){
        return true;
    }

    if(root == NULL || root1 == NULL){
        return false;
    }

    if(root->val != root1->val){
        return false;
    }

    return check(root->left, root1->left) &&
           check(root->right, root1->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(subRoot == NULL){
        return true;
    }

    if(root == NULL){
        return false;
    }

    if(check(root, subRoot)){
        return true;
    }

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}