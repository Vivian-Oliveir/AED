//12 ms
#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int num;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Pilha;

int* nextGreaterElements( int* nums, int numsSize, int* returnSize );
Pilha *criaPilha( void );
void PUSH( Pilha *topo, int n );
void POP( Pilha *topo );
void CLEAR( Pilha *topo );

int main() {
    int nums[] = {3, 8, 4, 1, 2};
    int *returnSize = malloc( sizeof( int ) );
    int *vetor = nextGreaterElements( nums, 5, returnSize );

    for( int m = 0; m < 5; m++ ) {
        printf( "%d ", *( vetor + m ) );
    }

    free( returnSize );
    free( vetor );
    return 0;
}

int* nextGreaterElements( int* nums, int numsSize, int* returnSize ) {
    Pilha *topoPilha;
    topoPilha = criaPilha();
    int i;

    int *vetor = ( int * )malloc( numsSize * sizeof( int ) );
    for ( i = 0; i < numsSize; i++ ) {
        vetor[i] = -1;
    }    

    for( i = ( 2 * ( numsSize - 1 ) ); i >= 0; i-- ) {
        while( *topoPilha != NULL && nums[i%numsSize] >= nums[( *topoPilha )->num] ) {
            POP( topoPilha );
        }

        if( *topoPilha != NULL && nums[i%numsSize] < nums[( *topoPilha )->num] ) {
            vetor[i%numsSize] = nums[( *topoPilha )->num];
        }

        PUSH( topoPilha, i%numsSize );
    }
    
    CLEAR( topoPilha );
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

void POP( Pilha *topo ) {
    Elem *p;
    p = *topo;
    *topo = p->prox;
    free( p );
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