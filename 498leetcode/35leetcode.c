#include <stdio.h>
#include <stdlib.h>

int searchInsert( int* nums, int numsSize, int target );
int buscaSubarvore( int *nums, int numsSize, int target, int comeco, int fim );

int main() {
    int nums[] = {1, 2, 5, 6};
    int numsSize, target, indice;
    target = 5;
    numsSize = 5;

    indice = searchInsert( nums, numsSize, target );
    printf( "%d", indice );

    return 0;
}

int searchInsert( int* nums, int numsSize, int target ) {
    int meio, comeco, fim, indice;
    numsSize -= 1;
    meio = numsSize / 2;

    if( meio == 0 ) {
        for( int i = 0; i <= numsSize; i++ ) {
            if( nums[i] >= target ) {
                return i;
            }
        }
        return ( numsSize + 1 );
    }

    if( nums[meio] > target ) {
        comeco = 0;
        fim = meio-1;
        indice = buscaSubarvore( nums, numsSize, target, comeco, fim );
        return indice;

    } else if( nums[meio] < target) {
        comeco = meio+1;
        fim = numsSize;
        indice = buscaSubarvore( nums, numsSize, target, comeco, fim );
        return indice;

    }  else if( nums[meio] == target ) {
        return meio;
    }
    return -1;
}

int buscaSubarvore( int *nums, int numsSize, int target, int comeco, int fim ) {
    int meio, indice;
    meio = (fim - comeco) / 2;

    if( meio == 0 ) {
        for( int i = 0; i <= numsSize; i++ ) {
            if ( nums[i] >= target ) {
                return i;
            }
        }
        return ( numsSize + 1 );
    }

    meio = meio + comeco;

    if( nums[meio] > target ) {
        comeco = comeco;
        fim = meio - 1;
        indice = buscaSubarvore( nums, numsSize, target, comeco, fim );
        return indice;

    } else if( nums[meio] < target ) {
        comeco = meio + 1;
        fim = numsSize;
        indice = buscaSubarvore( nums, numsSize, target, comeco, fim );
        return indice;

    } else if( nums[meio] == target ) {
        return meio;
    }
    return -1;
}