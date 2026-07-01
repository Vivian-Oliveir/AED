//124. Binary Tree Maximum Path Sum
//A path in a binary tree is a sequence of nodes where each pair of adjacent 
//nodes in the sequence has an edge connecting them. A node can only appear in 
//the sequence at most once. Note that the path does not need to pass through 
//the root.
//The path sum of a path is the sum of the node's values in the path.
//Given the root of a binary tree, return the maximum path sum of any non-empty 
//path.
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
int maxPathSum(struct TreeNode* root);
int maxPathComparando(struct TreeNode *root, int maiorCaminho, int *max);

int main(){
    struct TreeNode *root;
    Inicializar(&root);
    Inserir(&root, 9);
    Inserir(&root, 10);
    Inserir(&root, -3);
    Inserir(&root, 4);
    Inserir(&root, 1);
    Inserir(&root, -6);

    int maxpath;
    maxpath = maxPathSum(root);
    printf("%d", maxpath);

    Liberar(&root);
    return 0;
}

int maxPathSum(struct TreeNode* root) {
    int *max = malloc(sizeof(int));
    *max = -100000;

    int retorno;
    maxPathComparando(root, 0, max);
    retorno = *max;

    free(max);
    return retorno;
}

int maxPathComparando(struct TreeNode *root, int maiorCaminho, int *max){
    int esq = 0, dir = 0, caminhoEsq = 0, caminhoDir = 0, caminhoTotal = 0;

    if( root == NULL ){
        return 0;
    }

    esq = maxPathComparando(root->left, maiorCaminho, max);
    dir = maxPathComparando(root->right, maiorCaminho, max);
    
    caminhoEsq = esq + root->val;
    caminhoDir = dir + root->val;
    caminhoTotal = esq + dir + root->val;


    if(caminhoEsq > root->val && caminhoEsq > caminhoDir){
        maiorCaminho = caminhoEsq;
    } else if(caminhoDir > root->val && caminhoDir > caminhoEsq){
        maiorCaminho = caminhoDir;
    } else {
        maiorCaminho = root->val;
    }

    if(caminhoTotal > *max){
        *max = caminhoTotal;
    }

    if(caminhoDir > *max){
        *max = caminhoDir;
    }

    if(caminhoEsq > *max){
        *max = caminhoEsq;
    }

    if(root->val > *max){
        *max = root->val;
    }

    return maiorCaminho;
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