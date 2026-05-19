//110. Balanced Binary Tree
//Given a binary tree, determine if it is height-balanced.
//|altura_esquerda - altura_direita| <= 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode* ArvBin;

void Inicializa( ArvBin *raiz );
void insere_ArvBin( ArvBin *p, int valor );
void Lista( ArvBin raiz );
bool isBalanced(struct TreeNode* root);
int CaminhoMaisLongo( struct TreeNode* root, int *marcador, int contador );

int main() {
    ArvBin root;
    Inicializa(&root);
    //root = [3,9,20,null,null,15,7]
    insere_ArvBin(&root, 20);
    insere_ArvBin(&root, 15);
    insere_ArvBin(&root, 30);
    insere_ArvBin(&root, 12);
    insere_ArvBin(&root, 16);
    insere_ArvBin(&root, 10);
    insere_ArvBin(&root, 14);
    Lista(root);
    if(isBalanced(root)){
        printf("É balanceada");
    } else {
        printf("Não é balanceada");
    }

    return 0;
}

bool isBalanced(struct TreeNode* root){
    if( root == NULL ){
        return true;
    }
    int *marcador;
    marcador = (int *)malloc(sizeof(int));
    *marcador = 1;
    int contador = 0;
    CaminhoMaisLongo(root, marcador, contador);
    return *marcador;
}

int CaminhoMaisLongo( struct TreeNode* root, int *marcador, int contador){
    int subArvoreEsq = 0, subArvoreDir = 0;
    if( root == NULL ){
        return contador;
    }
    contador++;
    subArvoreEsq = CaminhoMaisLongo(root->left, marcador, contador);
    subArvoreDir = CaminhoMaisLongo(root->right, marcador, contador);

    if( abs(subArvoreEsq - subArvoreDir) > 1){
        *marcador = 0;
    }

    if(subArvoreEsq > subArvoreDir){
        return subArvoreEsq;
    }

    return subArvoreDir;
}

void Inicializa( ArvBin *raiz ) {
    *raiz = NULL;
}
void insere_ArvBin( ArvBin *p, int valor ) {
    if( *p == NULL ){
        *p = (ArvBin)malloc(sizeof(struct TreeNode));
        (*p)->val = valor;
        (*p)->left = NULL;
        (*p)->right = NULL;
    } else if(valor < (*p)->val){
        insere_ArvBin(&(*p)->left, valor);
        return;
    } else if(valor > (*p)->val){
        insere_ArvBin(&(*p)->right, valor);
        return;
    } else{
        return;
    }
}

void Lista( ArvBin raiz ){
    if( raiz == NULL ) {
        return;
    }
    Lista( raiz->left );
    printf( "%d\n", raiz->val );
    Lista( raiz->right );
}