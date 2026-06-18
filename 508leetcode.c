//508. Most Frequent Subtree Sum
//Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, 
//return all the values with the highest frequency in any order.
//The subtree sum of a node is defined as the sum of all the node values formed by the subtree 
//rooted at that node (including the node itself).
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
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize);
int colocaVetor(struct TreeNode *root, int *i, int *vetor);

int main(){
    struct TreeNode *root;
    Inicializar(&root);
    Inserir(&root, 10);
    Inserir(&root, 5);
    Inserir(&root, 13);
    Inserir(&root, 2);
    Inserir(&root, 7);
    Inserir(&root, 6);
    Inserir(&root, 8);
    Inserir(&root, 12);
    Inserir(&root, 14);

    int *returnSize, *somas;
    returnSize = malloc(sizeof(int));
    *returnSize = 0;
    somas = findFrequentTreeSum(root, returnSize);

    for(int i = 0; i < *returnSize; i++){
        printf("%d ", somas[i]);
    }

    free(somas);
    free(returnSize);
    Liberar(&root);
    return 0;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    int vetor[10000], *i, k, j;
    i = malloc(sizeof(int));
    *i = 0;

    colocaVetor(root, i, vetor);

    int m[10000][2];
    for(j = 0; j < (*i); j++){
        for(k = 0; k < j; k++){
            if(m[k][0] == vetor[j]){
                m[k][1]++;
            }
        }
        if(k == j){
            m[k][0] = vetor[k];
            m[k][1] = 1;
        }
    }

    int maiorNumero = m[0][1];
    for(j = 0; j <= k; j++){
        if(m[j][1] > maiorNumero){
            maiorNumero = m[j][1];
        }
    }
    

    int *numMaisFreq, g = 0;
    numMaisFreq = malloc(sizeof(int));
    for(j = 0; j <= k; j++){
        if(m[j][1] == maiorNumero){
            numMaisFreq[g] = m[j][0];
            g++;
            numMaisFreq = realloc(numMaisFreq, (g+1) * sizeof(int));
        }
    }

    free(i);
    *returnSize = g;
    return numMaisFreq;
}

int colocaVetor(struct TreeNode *root, int *i, int *vetor){
    int somaEsquerda = 0, somaDireita = 0;
    if(root == NULL){
        return 0;
    }

    somaEsquerda = colocaVetor(root->left, i, vetor);
    somaDireita = colocaVetor(root->right, i, vetor);

    vetor[*i] = somaDireita + somaEsquerda + root->val;
    (*i)++;
    root->val = somaDireita + somaEsquerda + root->val;

    return root->val;
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