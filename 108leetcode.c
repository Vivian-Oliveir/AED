//108. Convert Sorted Array to Binary Search Tree
//Given an integer array nums where the elements are sorted in ascending order, 
//convert it to a height-balanced binary search tree.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;     
    struct TreeNode *right;
};

void Inicializa(struct TreeNode **root);
void Libera(struct TreeNode **root);
void Lista(struct TreeNode *root);
void Insere(struct TreeNode **root, int val);
struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
void divide(struct TreeNode *root, int comeco, int fim, int *nums);

int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    Lista(sortedArrayToBST(nums, 5));
    return 0;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root;
    Inicializa(&root);
    int meio;
    meio = numsSize/2;
    Insere(&root, nums[meio]);
    divide(root, 0, meio-1, nums);
    divide(root, meio+1, numsSize-1, nums);
    return root;
}

void divide(struct TreeNode *root, int comeco, int fim, int *nums){
    if(comeco > fim){
        return;
    }
    int meio;
    meio = ((fim - comeco)/2) + comeco;
    Insere(&root, nums[meio]);
    divide(root, comeco, meio-1, nums);
    divide(root, meio+1, fim, nums);
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

void Insere(struct TreeNode **root, int val){
    if(*root == NULL){
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if( val < (*root)->val ){
        Insere(&(*root)->left, val);
    } else if( val > (*root)->val ){
        Insere(&(*root)->right, val);
    }
}

void Lista(struct TreeNode *root){
    if( root == NULL ){
        return;
    }
    Lista(root->left);
    printf("%d ", root->val);
    Lista(root->right);
}