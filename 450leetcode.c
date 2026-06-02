//450. Delete Node in a BST
//Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
//Return the root node reference (possibly updated) of the BST.
//Basically, the deletion can be divided into two stages:
//Search for a node to remover.
//If the node is found, delete the node.
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
struct TreeNode* deleteNode(struct TreeNode* root, int key);
void remover(struct TreeNode** root, int key);
struct TreeNode* removerAtual(struct TreeNode *atual);

int main() {
    struct TreeNode *root;
    Inicializa(&root);
    Insere(&root, 50);
    Insere(&root, 30);
    Insere(&root, 70);
    Insere(&root, 40);
    Insere(&root, 60);
    Insere(&root, 80);
    root = deleteNode(root, 50);
    Lista(root);
    Libera(&root);
    return 0;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    remover(&root, key);
    return root;
}

void remover(struct TreeNode** root, int key){
    if(root == NULL){
        return;
    }
    struct TreeNode *ant = NULL;
    struct TreeNode *atual = *root;
    while(atual != NULL){
        if(key == atual->val){
            if(atual == *root)
                *root = removerAtual(atual);
            else{
                if(ant->right == atual){
                    ant->right = removerAtual(atual);
                }
                else{
                    ant->left = removerAtual(atual);
                }
            }
            return;
        }
        ant = atual;
        if(key > atual->val){
            atual = atual->right;
        }
        else{
            atual = atual->left;
        }
    }
    return;
}

struct TreeNode* removerAtual(struct TreeNode *atual){
    struct TreeNode *node1, *node2;
    if(atual->left == NULL){
        node2 = atual->right;
        return node2;
    }
    node1 = atual;
    node2 = atual->left;
    while(node2->right != NULL){
        node1 = node2;
        node2 = node2->right;
    }
    if(node1 != atual){
        node1->right = node2->left;
        node2->left = atual->left;
    }
    node2->right = atual->right;
    free(atual);
    return node2;
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