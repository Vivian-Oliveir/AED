//94. Binary Tree Inorder Traversal
//Given the root of a binary tree, return the inorder traversal of its nodes' values
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Inicializa(struct TreeNode** root);
void Insere(struct TreeNode** root, int val);
void Libera(struct TreeNode** root);
int* inorderTraversal(struct TreeNode* root, int* returnSize);
void colocaOrdem(struct TreeNode* root, int* returnSize, int** numeros);

int main(){
    struct TreeNode *root;
    Inicializa(&root);
    Insere(&root, 5);
    Insere(&root, 3);
    Insere(&root, 6);
    Insere(&root, 4);
    Insere(&root, 2);
    Insere(&root, 7);

    int *vetor, *returnSize;
    returnSize = malloc(sizeof(int));
    *returnSize = 0;
    vetor = inorderTraversal(root, returnSize);

    for(int i=0; i<(*returnSize); i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);
    free(returnSize);
    Libera(&root);
    return 0;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *numeros = malloc(sizeof(int));
    *returnSize = 0;
    colocaOrdem(root, returnSize, &numeros);
    return numeros;
}

void colocaOrdem(struct TreeNode* root, int* returnSize, int** numeros) {
    if(root == NULL){
        return;
    }
    colocaOrdem(root->left, returnSize, numeros);
    *(*numeros + *returnSize) = root->val;
    (*returnSize)++;
    *numeros = realloc(*numeros, ((*returnSize) + 1)*(sizeof(int)));
    colocaOrdem(root->right, returnSize, numeros);
}

void Inicializa(struct TreeNode** root){
    *root = NULL;
}

void Insere(struct TreeNode** root, int val){
    if((*root) == NULL){
        (*root) = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    } else if(val < (*root)->val){
        Insere(&(*root)->left, val);
        return;
    } else if(val > (*root)->val){
        Insere(&(*root)->right, val);
        return;
    }
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