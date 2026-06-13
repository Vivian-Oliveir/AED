//222. Count Complete Tree Nodes
//Given the root of a complete binary tree, return the number of the nodes in the tree.
//According to Wikipedia, every level, except possibly the last, is completely filled in a 
//complete binary tree, and all nodes in the last level are as far left as possible. It can 
//have between 1 and 2h nodes inclusive at the last level h.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Inicializa(struct TreeNode** root);
void Insere(struct TreeNode** root, int val);
void Lista(struct TreeNode* root);
void Libera(struct TreeNode** root);
int countNodes(struct TreeNode* root);

int main(){
    struct TreeNode *root;
    Inicializa(&root);
    Insere(&root, 7);
    Insere(&root, 4);
    Insere(&root, 3);
    Insere(&root, 5);
    Insere(&root, 8);
    Insere(&root, 9);
    Lista(root);
    
    printf("\nNúmero de nós: %d", countNodes(root));

    Libera(&root);
    return 0;
}

int countNodes(struct TreeNode* root) {
    int nodes = 0;

    if(root == NULL){
        return nodes;
    }

    nodes++;
    nodes += countNodes(root->left);
    nodes += countNodes(root->right);
    
    return nodes;
}

void Inicializa(struct TreeNode** root) {
    *root = NULL;
}

void Insere(struct TreeNode** root, int val) {
    if( *root == NULL ) {
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->val = val;
        return;
    } else if( val < (*root)->val ) {
        Insere(&(*root)->left, val);
        return;
    } else if( val > (*root)->val ) {
        Insere(&(*root)->right, val);
        return;
    }
}

void Lista(struct TreeNode* root) {
    if( root == NULL ) {
        return;
    }

    Lista(root->left);
    printf("%d ", root->val);
    Lista(root->right);
}

void Libera(struct TreeNode** root) {
    if( *root == NULL ) {
        return;
    }

    Libera(&(*root)->left);
    Libera(&(*root)->right);
    free(*root);
    *root = NULL;
}