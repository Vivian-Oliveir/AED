#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder( int** mat, int matSize, int* matColSize, int* returnSize );

int main(){
    int **mat, i, j, *diagonalOrder, *returnSize, *matColSize;
    mat = (int **)malloc( 5 * sizeof(int *) );
    returnSize = (int *)malloc( sizeof(int) );
    matColSize = (int *)malloc( sizeof(int) );
    *matColSize = 3;

    for ( i = 0; i < 5; i++ ) {
        mat[i] = (int *)malloc( 3 * sizeof(int) );
    }

    for ( i = 0; i < 5; i++ ) {
        for ( j = 0; j < 3; j++ ) {
            printf("Digite um número: ");
            scanf("%d", &mat[i][j]);
        }  
    }

    for ( i = 0; i < 5; i++ ) {
        for ( j = 0; j < 3; j++ ) {
            printf("\t%d", mat[i][j]);
        }  
        printf("\n");
    }

    diagonalOrder = findDiagonalOrder( mat, 5, matColSize, returnSize );
    printf("Ordem na diagonal: \n");
    for ( i = 0; i < *returnSize; i++ ) {
        printf("%d ", diagonalOrder[i]);
    }

    for ( i = 0; i < 5; i++ ) {
        free( mat[i] );
    }
    
    free( mat );
    free( diagonalOrder );
    free( returnSize );
    free( matColSize );

    return 0;
}

int* findDiagonalOrder( int** mat, int matSize, int* matColSize, int* returnSize ) {
    int *vetor;
    int linha = 0, coluna = 0;
    int i = 0, pulei_linha = 0, pulei_coluna = 0;

    vetor = (int *)malloc( 100000 * sizeof(int) );
    *(vetor+i) = mat[linha][coluna];
    i++;

    while ( linha < matSize-1 || coluna < *matColSize-1 ) {
        if ( coluna+1 < *matColSize && ( linha == 0 || linha == matSize-1 ) ) {
            coluna++;
            *(vetor+i) = mat[linha][coluna];
            i++;
            pulei_coluna = 1;

            while ( coluna-1 >= 0 && linha+1 < matSize ) { 
                linha++;
                coluna--;
                *(vetor+i) = mat[linha][coluna];
                i++;
                pulei_coluna = 0;
            }

            if ( pulei_coluna == 1 ) { 
                while ( linha-1 >= 0 && coluna+1 < *matColSize ) {
                    linha--;
                    coluna++;
                    *(vetor+i) = mat[linha][coluna];
                    i++;
                }
            } 
        }

        if ( linha+1 < matSize && ( coluna == 0 || coluna == *matColSize-1 ) ) {
            linha++;
            *(vetor+i) = mat[linha][coluna];
            i++;
            pulei_linha = 1;
        
            while ( linha-1 >= 0 && coluna+1 < *matColSize ) {
                linha--;
                coluna++;
                *(vetor+i) = mat[linha][coluna];
                i++;
                pulei_linha = 0;
            } 

            if ( pulei_linha == 1) {
                while ( coluna-1 >= 0 && linha+1 < matSize ) {
                    linha++;
                    coluna--;
                    *(vetor+i) = mat[linha][coluna];
                    i++;
                }
            }
        }
    
        if ( linha == matSize-1 && coluna == *matColSize-1 ) {
            break;
        }
    }

    *returnSize = i;
    return vetor;
}
