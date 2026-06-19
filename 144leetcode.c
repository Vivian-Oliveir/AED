//144. Binary Tree Preorder Traversal
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
int* preorderTraversal(struct TreeNode* root, int* returnSize);
void preOrdem(struct TreeNode *root, int *returnSize, int **vetor);

int main(){
    struct TreeNode *root;
    Inicializar(&root);
    Inserir(&root, 6);
    Inserir(&root, 5);
    Inserir(&root, 7);
    Inserir(&root, 8);

    int *returnSize, *vetor;
    returnSize = malloc(sizeof(int));
    vetor = preorderTraversal(root, returnSize);

    for(int i = 0; i < (*returnSize); i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);
    free(returnSize);
    Liberar(&root);
    return 0;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *vetor;
    vetor = malloc(sizeof(int));
    *returnSize = 0;
    preOrdem(root, returnSize, &vetor);
    return vetor;
}

void preOrdem(struct TreeNode *root, int *returnSize, int **vetor) {
    if(root == NULL){
        return;
    }
    (*vetor)[*returnSize] = root->val;
    (*returnSize)++;
    *vetor = realloc(*vetor, ((*returnSize) + 1) * sizeof(int));
    preOrdem(root->left, returnSize, vetor);
    preOrdem(root->right, returnSize, vetor);
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