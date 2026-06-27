//112. Path Sum
//Given the root of a binary tree and an integer targetSum, return true if the tree has a 
//root-to-leaf path such that adding up all the values along the path equals targetSum.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Inicializar(struct TreeNode **root);
void Inserir(struct TreeNode **root, int val);
void Liberar(struct TreeNode **root);
void Listar(struct TreeNode *root);
bool hasPathSum(struct TreeNode* root, int targetSum);
int soma(struct TreeNode *root, int targetSum, int somaAtual);

int main(){
    struct TreeNode *root;
    Inicializar(&root);
    Inserir(&root, 1);
    Inserir(&root, 2);

    if(hasPathSum(root, 0)){
        printf("Tem um caminho que dá a soma");
    } else {
        printf("Não tem um caminho que dá a soma");
    }

    Liberar(&root);
    return 0;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    int somaAtual = 0, marcador;
    if(root == NULL){
        return false;
    }

    marcador = soma(root, targetSum, somaAtual);
    if(marcador == targetSum){
        return true;
    }

    return false;
}

int soma(struct TreeNode *root, int targetSum, int somaAtual){
    int somaEsq = targetSum - 1, somaDir = targetSum - 1;
    if(root->left == NULL && root->right == NULL){
        somaAtual += root->val;
        return somaAtual;
    }

    somaAtual += root->val;
    if(root->left != NULL){
        somaEsq = soma(root->left, targetSum, somaAtual); 
    }
    if(root->right != NULL){
        somaDir = soma(root->right, targetSum, somaAtual);
    }

    if(somaEsq == targetSum){
        return somaEsq;
    } else if(somaDir == targetSum){
        return somaDir;
    }

    return targetSum - 1;
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