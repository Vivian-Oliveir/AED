//Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//A valid BST is defined as follows:
//The left subtree of a node contains only nodes with keys strictly less than the node's key.
//The right subtree of a node contains only nodes with keys strictly greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;     
    struct TreeNode *right;
};

void Inicializa(struct TreeNode **root);
void Libera(struct TreeNode **root);
void Lista(struct TreeNode *root);
void Insere(struct TreeNode **root);
bool isValidBST(struct TreeNode* root);
void valida(struct TreeNode* root, struct TreeNode* rootInicial, int *i);
void esquerda(struct TreeNode *root, struct TreeNode *rootInicial, int *i);
void direita(struct TreeNode *root, struct TreeNode *rootInicial, int *i);

int main() {
    struct TreeNode *root;
    Inicializa(&root);
    Insere(&root);
    if(isValidBST(root)){
        printf("Válida\n");
    }else {
        printf("Inválida\n");
    }

    Libera(&root);
    return 0;
}

bool isValidBST(struct TreeNode* root) {
    int *i = malloc(sizeof(int));
    *i = 1;
    valida(root, root, i);
    return *i;
}

void valida(struct TreeNode* root, struct TreeNode* rootInicial, int *i) {
    if( root == NULL ){
        return;
    }
    esquerda(root->left, rootInicial, i);
    direita(root->right, rootInicial, i);
    while(rootInicial != NULL && (rootInicial->left != NULL || rootInicial->right != NULL)){
        if(root->left != NULL){
            rootInicial = rootInicial->left;
            root = rootInicial;
            if(root->left != NULL)
                esquerda(root->left, rootInicial, i);
            if(root->right != NULL)
                direita(root->right, rootInicial, i);
        }
        if(root->right != NULL){
            rootInicial = rootInicial->right;
            root = rootInicial;
            if(root->left != NULL)
                esquerda(root->left, rootInicial, i);
            if(root->right != NULL)
                direita(root->right, rootInicial, i);
        }
    }
    return;
}

void esquerda(struct TreeNode *root, struct TreeNode *rootInicial, int *i){
    if( root == NULL ){
        return;
    }
    
    if(root->val >= rootInicial->val){
        *i = 0;
    }

    esquerda(root->left, rootInicial, i);
    esquerda(root->right, rootInicial, i);
}

void direita(struct TreeNode *root, struct TreeNode *rootInicial, int *i){
    if( root == NULL ){
        return;
    }
    
    if(root->val <= rootInicial->val){
        *i = 0;
    }

    direita(root->left, rootInicial, i);
    direita(root->right, rootInicial, i);
}

void Inicializa(struct TreeNode **root){
    *root = NULL;
}

void Libera(struct TreeNode **root){
    if(*root == NULL){
        return;
    }
    Libera(&(*root)->left);
    Libera(&(*root)->right);
    free(*root);
    *root = NULL;
}

void Lista(struct TreeNode *root){
    if( root == NULL ){
        return;
    }
    Lista(root->left);
    printf("%d ", root->val);
    Lista(root->right);
}

void Insere(struct TreeNode **root){
    *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*root)->val = 45;
    (*root)->right = NULL;
    (*root)->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*root)->left->val = 42;
    (*root)->left->left = NULL;
    (*root)->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*root)->left->right->val = 44;
    (*root)->left->right->right = NULL;
    (*root)->left->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*root)->left->right->left->val = 43;
    (*root)->left->right->left->right = NULL;
    (*root)->left->right->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*root)->left->right->left->left->val = 41;
    (*root)->left->right->left->left->left = NULL;
    (*root)->left->right->left->left->right = NULL;
}