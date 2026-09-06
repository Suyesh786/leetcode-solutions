int max(int a, int b){
    return (a > b) ? a : b;
}

int height(struct TreeNode* root, int* diameter){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left, diameter);
    int right = height(root->right, diameter);

    // Diameter passing through this node
    int current = left + right;

    if(current > *diameter){
        *diameter = current;
    }

    // Return height of this node
    return 1 + max(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;

    height(root, &diameter);

    return diameter;
}