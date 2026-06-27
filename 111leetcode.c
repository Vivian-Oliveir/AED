//111. Minimum Depth of Binary Tree
//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to 
//the nearest leaf node.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Inicializar(struct TreeNode **root);
void Inserir(struct TreeNode **root, int val);
void Liberar(struct TreeNode **root);
void Listar(struct TreeNode *root);
int minDepth(struct TreeNode* root);
int profundidade(struct TreeNode* root, int i);

int main(){
    struct TreeNode *root;
    Inicializar(&root);
    Inserir(&root, 3);
    Inserir(&root, 20);
    Inserir(&root, 15);
    Inserir(&root, 22);

    int min;
    min = minDepth(root);
    printf("%d ", min);

    Liberar(&root);
    return 0;
}

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

void Inicializar(struct TreeNode **root){
    *root = NULL;
}

void Inserir(struct TreeNode **root, int val){
    if(*root == NULL){
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->val = val;
        return;
    } else if(val < (*root)->val){
        Inserir(&(*root)->left, val);
        return;
    } else if(val > (*root)->val){
        Inserir(&(*root)->right, val);
        return;
    }
}

void Liberar(struct TreeNode **root){
    if(*root == NULL){
        return;
    }
    Liberar(&(*root)->left);
    Liberar(&(*root)->right);
    free(*root);
    *root = NULL;
}

void Listar(struct TreeNode *root){
    if(root == NULL){
        return;
    }
    Listar(root->left);
    printf("%d ", root->val);
    Listar(root->right);
}