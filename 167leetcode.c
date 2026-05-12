//Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
//find two numbers such that they add up to a specific target number. Let these two numbers be 
//numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
//Return the indices of the two numbers index1 and index2, each incremented by one, as an 
//integer array [index1, index2] of length 2.
//The tests are generated such that there is exactly one solution. You may not use the same 
//element twice.
//Your solution must use only constant extra space.

//Input: numbers = [2,7,11,15], target = 9
//Output: [1,2]
//Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

#include <stdio.h>
#include <stdlib.h>

int* twoSum( int* numbers, int numbersSize, int target, int* returnSize );
int procuraMeio( int* numbers, int comeco, int fim, int target, int* i1, int* i2 );

int main() {
    int numbers[] = {3,24,50,79,88,150,345};
    int target = 200, numbersSize = 7;
    int *retorno, *returnSize;

    returnSize = ( int * )malloc( sizeof( int ) );
    retorno = twoSum( numbers, numbersSize, target, returnSize );

    printf( "%d %d", retorno[0], retorno[1] );
    free( retorno );
    free( returnSize );
    return 0;
}

int* twoSum( int* numbers, int numbersSize, int target, int* returnSize ) {
    int *indices, *i1, *i2;
    indices = ( int * )malloc( 2 * sizeof( int ) );
    i1 = ( int * )malloc( sizeof( int ) );
    i2 = ( int * )malloc( sizeof( int ) );

    int comeco, fim;
    comeco = 0;
    fim = numbersSize - 1;
    procuraMeio( numbers, comeco, fim, target, i1, i2 );

    indices[0] = *i1 + 1;
    indices[1] = *i2 + 1;
    *returnSize = 2;
    free( i1 );
    free( i2 );
    return indices;
}

int procuraMeio( int* numbers, int comeco, int fim, int target, int* i1, int* i2 ) {
    if( numbers[comeco] + numbers[fim] == target ) {
        *i1 = comeco;
        *i2 = fim;

    }else if( numbers[comeco] + numbers[fim] < target ) {
        comeco++;
        procuraMeio( numbers, comeco, fim, target, i1, i2 );

    }else if( numbers[comeco] + numbers[fim] > target ) {
        fim--;
        procuraMeio( numbers, comeco, fim, target, i1, i2 );
    }
    return -1;
}