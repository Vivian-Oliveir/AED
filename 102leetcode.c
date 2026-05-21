//102. Binary Tree Level Order Traversal
//Given the root of a binary tree, return the level order traversal of its nodes' 
//values. (i.e., from left to right, level by level).
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct elemento {
    struct TreeNode *dados;
    struct elemento *prox;
}Elem;

typedef struct fila {
    Elem *inicio;
    Elem *final;
    int qtd;
}Fila;

typedef struct TreeNode* Apontador;

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

void colocaFila(Fila *f, struct TreeNode *no);
struct TreeNode* tiraFila(Fila *f);
int achaAltura(struct TreeNode *root, int altura);

void Inicializa(Apontador *raiz);
void Insere(Apontador *raiz, int val);
void Lista(Apontador raiz);
void Libera(Apontador *raiz);

int main(){
    Apontador raiz;
    Inicializa(&raiz);
    Insere(&raiz, 3);
    Insere(&raiz, 2);
    Insere(&raiz, 9);
    Insere(&raiz, 8);
    Insere(&raiz, 10);
    int **vetor, returnSize, *returnColumnSizes;
    vetor = levelOrder(raiz, &returnSize, &returnColumnSizes);
    for(int i=0; i<returnSize; i++){
        for(int j=0; j<returnColumnSizes[i]; j++){
            printf("%d ", vetor[i][j]);
        }
    }

    Libera(&raiz);
    return 0;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int **vetor, i = 0, altura, k;
    altura = achaAltura(root, 0);

    vetor = (int **)malloc(altura * sizeof(int *));
    for(k=0; k<altura; k++){
        vetor[k] = (int *)malloc(sizeof(int));
    }

    *returnColumnSizes = (int *)malloc(altura * sizeof(int));

    Fila f;
    f.inicio = NULL;
    f.final = NULL;
    f.qtd = 0;

    colocaFila(&f, root);

    while(f.inicio != NULL){
        int elementosNivel = f.qtd;
        vetor[i] = realloc(vetor[i], elementosNivel * sizeof(int));
        (*returnColumnSizes)[i] = elementosNivel;

        for(k=0; k<elementosNivel; k++){
            struct TreeNode *atual = tiraFila(&f);
            vetor[i][k] = atual->val;

            if(atual->left != NULL){
                colocaFila(&f, atual->left);
            }
            if(atual->right != NULL){
                colocaFila(&f, atual->right);
            }
        }
        i++;
    }
    *returnSize = i;
    return vetor;
}

int achaAltura(struct TreeNode *root, int altura){
    int alturaEsq = 0, alturaDir = 0, alturaMax = 0;

    if(root == NULL)
        return altura;
    altura++;
    alturaEsq = achaAltura(root->left, altura);
    alturaDir = achaAltura(root->right, altura);

    if(alturaDir > alturaEsq){
        alturaMax = alturaDir;
    } else {
        alturaMax = alturaEsq;
    }

    return alturaMax;
}

void colocaFila(Fila *f, struct TreeNode *no){
    Elem *nova = (Elem *)malloc(sizeof(Elem));
    nova->dados = no;
    nova->prox = NULL;

    if(f->final != NULL){
        f->final->prox = nova;
    } else {
        f->inicio = nova;
    }

    f->final = nova;
    f->qtd++;
    
}

struct TreeNode* tiraFila(Fila *f){
    if(f->inicio == NULL){
        return NULL;
    }

   Elem *temp = f->inicio;

    struct TreeNode *no = temp->dados;

    f->inicio = f->inicio->prox;

    if(f->inicio == NULL){
        f->final = NULL;
    }

    f->qtd--;
    free(temp);

    return no;
}

void Inicializa(Apontador *raiz){
    *raiz = NULL;
}

void Insere(Apontador *raiz, int val){
    if(*raiz == NULL){
        *raiz = (Apontador)malloc(sizeof(struct TreeNode));
        (*raiz)->val = val;
        (*raiz)->left = NULL;
        (*raiz)->right = NULL;
    }else if(val > (*raiz)->val){
        Insere(&(*raiz)->right, val);
        return;
    } else if(val < (*raiz)->val){
        Insere(&(*raiz)->left, val);
        return;
    } else {
        return;
    }
}
void Lista(Apontador raiz) {
    if(raiz == NULL){
        return;
    }
    Lista(raiz->left);
    printf("%d\n", raiz->val);
    Lista(raiz->right);
}
void Libera(Apontador *raiz){
    if(*raiz == NULL){
        return;
    }
    Libera(&(*raiz)->left);
    Libera(&(*raiz)->right);
    free(*raiz);
    *raiz = NULL;
}