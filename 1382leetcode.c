//1382. Balance a Binary Search Tree
//Given the root of a binary search tree, return a balanced binary search tree with the same 
//node values. If there is more than one answer, return any of them.
//A binary search tree is balanced if the depth of the two subtrees of every node never differs 
//by more than 1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
};

void Inicializa(struct TreeNode **root);
void Insere(struct TreeNode **root, int val);
void Libera(struct TreeNode **root);
void Lista(struct TreeNode *root);
struct TreeNode* balanceBST(struct TreeNode* root);
void arvorePvetor(struct TreeNode* root, int *i, int *vetorArvore);
void quicksort(int *vetorArvore, int left, int right);
void insereNovaArvore(struct TreeNode **root2, int *vetorArvore, int comeco, int fim);

int main(){
    struct TreeNode *root;
    Inicializa(&root);
    Insere(&root, 1);
    Insere(&root, 2);
    Insere(&root, 3);
    Insere(&root, 4);

    srand(time(NULL));
    balanceBST(root);

    Libera(&root);
    return 0;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    int vetorArvore[10000], *i;
    i = malloc(sizeof(int));
    *i = 0;

    arvorePvetor(root, i, vetorArvore);
    quicksort(vetorArvore, 0, (*i)-1);

    Libera(&root);

    int meio = (*i)/2;
    struct TreeNode *root2;
    Inicializa(&root2);
    Insere(&root2, vetorArvore[meio]);
    
    insereNovaArvore(&(root2->left), vetorArvore, 0, meio - 1);
    insereNovaArvore(&(root2->right), vetorArvore, meio + 1, (*i) - 1);
    Lista(root2);
    return root2;
}

void arvorePvetor(struct TreeNode* root, int *i, int *vetorArvore){
    if(root == NULL){
        return;
    }
    vetorArvore[*i] = root->val;
    (*i)++;
    arvorePvetor(root->left, i, vetorArvore);
    arvorePvetor(root->right, i, vetorArvore);
}

void quicksort(int *vetorArvore, int left, int right){
    int meio, temp, i, j, numAleatorio;
    numAleatorio = left + rand() % (right - left + 1);
    i = left;
    j = right;
    meio = vetorArvore[numAleatorio];
    do { 
        while(vetorArvore[i] < meio){
            i++;
        }
        while(meio < vetorArvore[j]){
            j--;
        }
        if( i <= j ){
            temp = vetorArvore[i];
            vetorArvore[i] = vetorArvore[j];
            vetorArvore[j] = temp;
            i++;
            j--;
        }
    } while( i <= j );

    if(left < j){
        quicksort(vetorArvore, left, j);
    }
    if(i < right){
        quicksort(vetorArvore, i, right);
    }
}

void insereNovaArvore(struct TreeNode **root2, int *vetorArvore, int comeco, int fim){
    if(fim - comeco == 1){
        Insere(&(*root2), vetorArvore[fim]);
        Insere(&(*root2), vetorArvore[comeco]);
        return;
    } else if(fim - comeco == 0){
        Insere(&(*root2), vetorArvore[comeco]);
        return;
    } else if( fim < comeco ){
        return;
    }
    
    int meio = (fim - comeco)/2;

    *root2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    (*root2)->left = NULL;
    (*root2)->right = NULL;
    (*root2)->val = vetorArvore[meio + comeco];
    insereNovaArvore(&(*root2)->left, vetorArvore, comeco, meio + comeco - 1);
    insereNovaArvore(&(*root2)->right, vetorArvore, meio + comeco + 1, fim);
}

void Inicializa(struct TreeNode **root) {
    *root = NULL;
}

void Insere(struct TreeNode **root, int val) {
    if(*root == NULL){
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->val = val;
    } else if(val < (*root)->val){
        Insere(&(*root)->left, val);
    } else if(val > (*root)->val){
        Insere(&(*root)->right, val);
    }
}

void Libera(struct TreeNode **root) {
    if(*root == NULL){
        return;
    }
    Libera(&(*root)->left);
    Libera(&(*root)->right);
    free(*root);
    *root = NULL;
}

void Lista(struct TreeNode *root) {
    if(root == NULL){
        return;
    }
    Lista(root->left);
    printf("%d ", root->val);
    Lista(root->right);
}