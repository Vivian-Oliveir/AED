//257. Binary Tree Paths
//Given the root of a binary tree, return all root-to-leaf paths in any order.
//A leaf is a node with no children.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Inicializa(struct TreeNode** root);
void Insere(struct TreeNode** root, int val);
void Lista(struct TreeNode* root);
void Libera(struct TreeNode** root);
char** binaryTreePaths(struct TreeNode* root, int* returnSize);
void paths(struct TreeNode* root, int* returnSize, char **v, char *path, int tam);

int main(){
    struct TreeNode *root;
    Inicializa(&root);
    Insere(&root, 5);
    Insere(&root, 3);
    Insere(&root, 6);
    Insere(&root, 2);

    int *returnSize;
    char **caminhos;
    returnSize = malloc(sizeof(int));
    caminhos = binaryTreePaths(root, returnSize);
    for(int i = 0; i < *returnSize; i++){
        printf("%s\n", caminhos[i]);
    }

    Libera(&root);
    free(caminhos);
    free(returnSize);
    return 0; 
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    char **v, path[1000];
    path[0] = '\0';
    v = (char **)malloc(100 * sizeof(char *));
    paths(root, returnSize, v, path, 0);
    return v;
}

void paths(struct TreeNode* root, int* returnSize, char **v, char *path, int tam){
    char temp[100];
    int tamanhoVoltar;
    if(root == NULL){
        return;
    }

    tamanhoVoltar = tam;

    if(root->left == NULL && root->right == NULL){
        sprintf(temp, "%d", root->val);
        strcat(path, temp);
        tam += strlen(temp);

        v[*returnSize] = malloc(strlen(path) + 1);
        strcpy(v[*returnSize], path);
        (*returnSize)++;

        path[tamanhoVoltar] = '\0';
        return;

    } else {
        sprintf(temp, "%d->", root->val);
        strcat(path, temp);
        tam += strlen(temp);

        paths(root->left, returnSize, v, path, tam);
        paths(root->right, returnSize, v, path, tam);
    }

    path[tamanhoVoltar] = '\0';
}


void Inicializa(struct TreeNode** root) {
    *root = NULL;
}

void Insere(struct TreeNode** root, int val) {
    if( *root == NULL ){
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    } else if( val < (*root)->val ){
        Insere(&(*root)->left, val);
        return;
    } else if( val > (*root)->val ){
        Insere(&(*root)->right, val);
        return;
    }
}

void Lista(struct TreeNode* root){
    if(root == NULL){
        return;
    }

    Lista(root->left);
    printf("%d ", root->val);
    Lista(root->right);
}

void Libera(struct TreeNode** root) {
    if(*root == NULL){
        return;
    }

    Libera(&(*root)->left);
    Libera(&(*root)->right);
    free(*root);
    *root = NULL;
}