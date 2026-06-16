//236. Lowest Common Ancestor of a Binary Tree
//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
//between two nodes p and q as the lowest node in T that has both p and q as descendants (where 
//we allow a node to be a descendant of itself).”
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Inicializar(struct TreeNode** root);
void Inserir(struct TreeNode** root, int val);
void Liberar(struct TreeNode** root);
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);
int* retornaComum(struct TreeNode* root, int* caminho, int a,  int *i, int tamanhoAntigo, int *marcador);
struct TreeNode* achaNo(struct TreeNode *root, int val);

int main(){
    struct TreeNode *root, *noComum;
    Inicializar(&root);
    Inserir(&root, 10);
    Inserir(&root, 5);
    Inserir(&root, 12);
    Inserir(&root, 2);
    Inserir(&root, 7);
    Inserir(&root, 6);
    Inserir(&root, 8);
    Inserir(&root, 11);

    noComum = lowestCommonAncestor(root, root->left->right->right, root->left);
    printf("%d", noComum->val);

    Liberar(&root);
    return 0;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *retorno;

    int caminho1[100000], caminho2[100000];
    int *tamanho1, *tamanho2, *marcador;
    tamanho1 = malloc(sizeof(int));
    tamanho2 = malloc(sizeof(int));
    marcador = malloc(sizeof(int));
    *tamanho1 = 0;
    *tamanho2 = 0;
    *marcador = 0;

    retornaComum(root, caminho1, p->val, tamanho1, 0, marcador);
    *marcador = 0;
    retornaComum(root, caminho2, q->val, tamanho2, 0, marcador);

    for(int i = (*tamanho1 - 1); i >= 0; i--){
        for(int j = (*tamanho2 - 1); j >= 0; j--){
            if(caminho1[i] == caminho2[j]){
                retorno = achaNo(root, caminho1[i]);
                free(tamanho1);
                free(tamanho2);
                free(marcador);
                return retorno;
            }
        }
    }
    free(tamanho1);
    free(tamanho2);
    free(marcador);
    return NULL;
}

int* retornaComum(struct TreeNode* root, int* caminho, int a,  int *i, int tamanhoAntigo, int *marcador){
    if(root == NULL){
        return caminho;
    }

    tamanhoAntigo = *i;

    if(*i < 100000){
        caminho[*i] = root->val;
        (*i)++;
    }

    if(root->val == a){
        *marcador = 1;
        tamanhoAntigo = *i;
        return caminho;
    }

    if(*marcador == 0){
        caminho = retornaComum(root->left, caminho, a, i, tamanhoAntigo, marcador);    
    }
    if(*marcador == 0){
        caminho = retornaComum(root->right, caminho, a, i, tamanhoAntigo, marcador);    
    }

    if(*marcador == 0){
        *i = tamanhoAntigo;   
    }
    return caminho;
}

struct TreeNode* achaNo(struct TreeNode *root, int val){
    struct TreeNode *p;
    if(root == NULL){
        return NULL;
    }
    if(root->val == val){
        return root;
    }
    p = achaNo(root->left, val);
    if(p == NULL){
        p = achaNo(root->right, val);
    }
    return p;
}

void Inicializar(struct TreeNode** root){
    *root = NULL;
}

void Inserir(struct TreeNode** root, int val){
    if(*root == NULL){
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if(val < (*root)->val){
        Inserir(&(*root)->left, val);
    } else if(val > (*root)->val){
        Inserir(&(*root)->right, val);
    }
}

void Liberar(struct TreeNode** root){
    if(*root == NULL){
        return;
    }

    Liberar(&(*root)->left);
    Liberar(&(*root)->right);
    free(*root);
    *root = NULL;
}