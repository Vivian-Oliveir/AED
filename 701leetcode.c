//You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
//Return the root node of the BST after the insertion. It is guaranteed that the new value does 
//not exist in the original BST.
//Notice that there may exist multiple valid ways for the insertion, as long as the tree remains 
//a BST after insertion. You can return any of them.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode* Apontador;
struct TreeNode* insertIntoBST(struct TreeNode* root, int val);
void insert(struct TreeNode** root, int val);
void Inicializa(Apontador *root);
void Libera(Apontador *root);
void Lista(Apontador root);

int main() {
    Apontador root;
    Inicializa(&root);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 6);
    Lista(root);
    Libera(&root);
    return 0;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    insert(&root, val);
    return root;
}
void insert(struct TreeNode** root, int val) {
    if(*root == NULL){
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->val = val;
        return;
    } else if((*root)->val > val) {
        insert(&(*root)->left, val);
        return;
    } else if((*root)->val < val){
        insert(&(*root)->right, val);
        return;
    }
}

void Inicializa(Apontador *root) {
    *root = NULL;
}

void Libera(Apontador *root) {
    if(*root == NULL){
        return;
    }
    Libera(&(*root)->left);
    Libera(&(*root)->left);
    free(*root);
    *root = NULL;
}

void Lista(Apontador root) {
    if(root == NULL){
        return;
    }
    Lista(root->left);
    printf("%d ", root->val);
    Lista(root->right);
}