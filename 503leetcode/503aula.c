#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElements( int* nums, int numsSize, int* returnSize );

int main() {
    int nums[] = {1, 2, 3, 4, 3};
    int *returnSize = malloc( sizeof( int ) );
    int *vetor = nextGreaterElements( nums, 5, returnSize );

    for( int m = 0; m < 5; m++ ) {
        printf( "%d ", nums[m] );
    }
    printf( "\n" );
    for( int m = 0; m < 5; m++ ) {
        printf( "%d ", *( vetor + m ) );
    }

    free( returnSize );
    free( vetor );
    return 0;
}

int* nextGreaterElements( int* nums, int numsSize, int* returnSize ) {
    int i, k;
    int *vetor = malloc( numsSize * sizeof( int ) );

    for( i = 0; i < numsSize; i++ ) {
        k = i + 1;
        while( k < numsSize && nums[i] >= nums[k] ) {
            k++;
        } 
        if( k == numsSize ) {
            k = 0;
            while( k < i && nums[i] >= nums[k] ) {
                k++;
            } 
        }

        if( nums[i] == nums[k] ) {
            *( vetor + i ) = -1;
        } else {
            *( vetor + i ) = nums[k];
        }
    }

    *returnSize = numsSize;
    return vetor;
}