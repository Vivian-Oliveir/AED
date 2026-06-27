int minDepth(struct TreeNode* root) {
    int i = 0;
    if(root == NULL){
        return 0;
    }
    return profundidade(root, i);
}

int profundidade(struct TreeNode* root, int i){
    int m = 100000, n = 100000;
    
    if(root->left == NULL && root->right == NULL){
        i++;
        return i;
    }
    
    i++;
    if(root->left != NULL){
        m = profundidade(root->left, i);    
    }
    if(root->right != NULL){
        n = profundidade(root->right, i);
    }

    if((m < n && m != 1) || (n == 1)){
        return m;
    }
    return n;
}