//Given an array of integers nums and an integer target, return indices of 
//the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you 
//may not use the same element twice.
//You can return the answer in any order.

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *vetor;
    vetor = (int *)malloc(3*sizeof(int));

    int i, j;
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            if(i!=j && (nums[i]+nums[j]==target)){
                *vetor = i;
                *(vetor+1) = j;
                *returnSize = 2;
                return vetor;
            }
        }
    }

    *returnSize = 0; //caso n ache dois números cuja soma dá o target
    return NULL;
}

int main(){
    int nums[] = {2, 1, 7};
    int numsSize = 3, target = 9, *vetormain, *returnSize;
    returnSize = (int*)malloc(sizeof(int));

    vetormain = (int *)malloc(3*sizeof(int));
    vetormain = twoSum(nums, numsSize, target, returnSize);
    printf("%d %d", *vetormain, *(vetormain+1));

    return 0;
}