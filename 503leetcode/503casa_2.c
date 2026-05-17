#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int num;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Pilha;

int* nextGreaterElements( int* nums, int numsSize, int* returnSize );
Pilha *criaPilha( void );
void PUSH( Pilha *topo, int n );
int Move_Pilha( Pilha *topo, Elem **numAtual );
void CLEAR( Pilha *topo );

int main() {
    int nums[] = {-1, 5, 4, 3, 2};
    int *returnSize = malloc( sizeof( int ) );
    int *vetor = nextGreaterElements( nums, 5, returnSize );

    for( int m = 0; m < 5; m++ ) {
        printf( "%d ", nums[m] );
    }
    printf( "\n ");
    for( int m = 0; m < 5; m++ ) {
        printf( "%d ", *( vetor + m ) );
    }

    free( returnSize );
    free( vetor );
    return 0;
}

int* nextGreaterElements( int* nums, int numsSize, int* returnSize ) {
    Pilha *topo;
    Elem *numAtual;
    topo = criaPilha();
    int i;

    int *vetor = ( int * )malloc( numsSize * sizeof( int ) );

    for( i = ( numsSize - 1 ); i >= 0; i-- ) {
        PUSH( topo, nums[i] );
    }

    numAtual = *topo;

    for( i = 0; i < numsSize ; i++ ) {
        vetor[i] = Move_Pilha( topo, &numAtual );
    }

    CLEAR( topo );

    *returnSize = numsSize;
    return vetor;
}

Pilha *criaPilha( void ) {
    Pilha *p = ( Pilha * )malloc( sizeof( Pilha ) );
    if( p != NULL ) {
        *p = NULL;
    }
    return p;
}

void PUSH( Pilha *topo, int n ) {
    Elem *novo;
    novo = ( Elem * )malloc( sizeof( Elem ) );
    novo->num = n;
    novo->prox = *topo;
    *topo = novo;
}

int Move_Pilha( Pilha *topo, Elem **numAtual ) {
    Elem *proc;
    proc = ( *numAtual )->prox;

    while( proc != NULL && proc->num <= ( *numAtual )->num ) {
        proc = proc->prox;
    }

    if( proc != NULL ) {
        *numAtual = ( *numAtual )->prox;
        return proc->num;
    } 

    proc = *topo;
    while( proc != *numAtual && proc->num <= ( *numAtual )->num ) {
        proc = proc->prox;
    }
    
    if( proc != *numAtual ) {
        *numAtual = ( *numAtual )->prox;
        return proc->num;
    } 

    *numAtual = ( *numAtual )->prox;
    return -1;
}

void CLEAR( Pilha *topo ) {
    if ( topo != NULL ) {
        Elem *no;
        while( ( *topo ) != NULL ) {
            no = *topo;
            *topo = ( *topo )->prox;
            free( no );
        }
        free( topo );
    }
}