//101. Symmetric Tree
//Given the root of a binary tree, check whether it is a mirror of 
//itself (i.e., symmetric around its center).
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Inicializa(struct TreeNode** root);
void Insere(struct TreeNode** root, int a, int b, int c, int d, int e, int f, int g);
void Lista(struct TreeNode* root);
void Libera(struct TreeNode** root);
bool isSymmetric(struct TreeNode* root);
bool simetrica(struct TreeNode* root, struct TreeNode* root2);

int main(){
    struct TreeNode* root;
    Inicializa(&root);
    Insere(&root, 1, 2, 2, 3, 4, 4, 8);
    Lista(root);

    if(isSymmetric(root)){
        printf("É simétrica");
    } else {
        printf("Não é simétrica");
    }

    Libera(&root);
    return 0;
}

bool isSymmetric(struct TreeNode* root) {
    return simetrica(root->left, root->right);
}

bool simetrica(struct TreeNode* root, struct TreeNode* root2) {
    bool l, r;
    if((root == NULL) && (root2 == NULL)){
        return true;
    } else if(((root == NULL) && (root2 != NULL)) || ((root != NULL) && (root2 == NULL))){
        return false;
    }
    
    if(root->val != root2->val){
        return false;
    }
    l = simetrica(root->left, root2->right);
    r = simetrica(root->right, root2->left);
    return (l && r);
}

void Inicializa(struct TreeNode** root) {
    *root = NULL;
}

void Insere(struct TreeNode** root, int a, int b, int c, int d, int e, int f, int g) {
    *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    (*root)->val = a;
    (*root)->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    (*root)->left->val = b;
        (*root)->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            (*root)->left->left->val = d;
            (*root)->left->left->left = NULL;
            (*root)->left->left->right = NULL;
        (*root)->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            (*root)->left->right->val = e;
            (*root)->left->right->left = NULL;
            (*root)->left->right->right = NULL; 
    (*root)->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    (*root)->right->val = c;
        (*root)->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            (*root)->right->left->val = f;
            (*root)->right->left->left = NULL;
            (*root)->right->left->right = NULL;
        (*root)->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            (*root)->right->right->val = g;
            (*root)->right->right->left = NULL;
            (*root)->right->right->right = NULL;
    
}

void Lista(struct TreeNode* root) {
    if(root == NULL) {
        return;
    }
    Lista(root->left);
    printf("%d ", root->val);
    Lista(root->right);
}

void Libera(struct TreeNode** root){
    if(*root == NULL){
        return;
    }

    Libera(&(*root)->left);
    Libera(&(*root)->right);
    free(*root);
    *root = NULL;
}