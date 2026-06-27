//404. Sum of Left Leaves
//Given the root of a binary tree, return the sum of all left leaves.
//A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
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
int sumOfLeftLeaves(struct TreeNode* root);
void somaNos(struct TreeNode *root, int *soma);

int main(){
    struct TreeNode *root;
    Inicializar(&root);
    Inserir(&root, 20);
    Inserir(&root, 15);
    Inserir(&root, 17);
    Inserir(&root, 16);
    Inserir(&root, 30);
    Inserir(&root, 29);
    Inserir(&root, 28);
    Inserir(&root, 33);

    int soma;
    soma = sumOfLeftLeaves(root);
    printf("%d ", soma);

    Liberar(&root);
    return 0;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int *soma = malloc(sizeof(int)), somaRetorno;
    *soma = 0;
    somaNos(root, soma);
    somaRetorno = *soma;
    free(soma);
    return somaRetorno;
}

void somaNos(struct TreeNode *root, int *soma){
    if(root->left != NULL){
        if(root->left->left == NULL && root->left->right == NULL){
            *soma += root->left->val;
        }
    }
    
    if(root->left != NULL){
        somaNos(root->left, soma);
    }
    if(root->right != NULL){
        somaNos(root->right, soma);
    }

    return;
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