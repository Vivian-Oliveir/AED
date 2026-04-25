//Given an m x n matrix mat, return an array of all the 
//elements of the array in a diagonal order.
#include <stdio.h>
#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize);

int main(){
    int **mat, i, j, *diagonalOrder, *returnSize, *colunas;

    mat = (int **)malloc(5*sizeof(int *));

    diagonalOrder = (int *)malloc(100*sizeof(int));

    returnSize = (int *)malloc(sizeof(int));

    colunas = (int *)malloc(sizeof(int));
    *colunas = 5;

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("Digite: ");
            mat[i][j] = 1+i;
        }  
    }

    findDiagonalOrder(mat, 5, colunas, returnSize);

    return 0;

}

//Note: The returned array must be malloced, assume caller calls free().

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int *vetor, linha, coluna, i=0;
    vetor = (int *)malloc(100000*sizeof(int));

    *(vetor+i) = mat[linha][coluna];
    i++;
    linha = 0;
    coluna = 1;
   
    while( linha != matSize && coluna != *matColSize ){
        while (coluna != 0) {
            *(vetor+i) = mat[linha][coluna];
            linha++;
            coluna--;
            i++;
        }
        linha++;
        while (linha != 0 ){
            *(vetor+i) = mat[linha][coluna];
            linha--;
            coluna++;
            i++;
        }
        coluna++;
        
    }
    if( linha == 0 && coluna == *matColSize){
        *(vetor+i) = mat[linha][coluna];
        i++;
        while ( *(vetor+i) != mat[matSize][*matColSize]);
        while( linha != matSize ){
            linha++;
            *(vetor+i) = mat[linha][coluna];
            i++;
            coluna--;
        }
        while( coluna != *matColSize ){
            coluna++;
            *(vetor+i) = mat[linha][coluna];
            i++;
            linha--;
        }
    }

    *returnSize = 1;
    return vetor;

}

// 0,0    0,1     0,2
//    1,0     1,1       1,2
//        2,0       2,1       2,2

//0,0    0,1    0,2     0,3     0,4

//1,0    1,1    1,2     1,3     1,4

//2,0    2,1    2,2     2,3     2,4

//3,0    3,1    3,2     3,3     3,4

//4,0    4,1    4,2     4,3     4,4
//1=até a linha ser zero
//2=até a coluna ser zero
//3=até a linha ser zero

// começa pra cima