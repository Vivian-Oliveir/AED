//You are given an integer array score of size n, where score[i] is the score of the ith 
//athlete in a competition. All the scores are guaranteed to be unique.
//The athletes are placed based on their scores, where the 1st place athlete has the highest 
//score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each 
//athlete determines their rank:
//The 1st place athlete's rank is "Gold Medal".
//The 2nd place athlete's rank is "Silver Medal".
//The 3rd place athlete's rank is "Bronze Medal".
//For the 4th place to the nth place athlete, their rank is their placement number 
//(i.e., the xth place athlete's rank is "x").
//Return an array answer of size n where answer[i] is the rank of the ith athlete.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** findRelativeRanks(int* score, int scoreSize, int* returnSize);

int main(){
    int score[] = {5, 4, 3, 2, 1};
    int *returnSize = malloc(sizeof(int));
    char **vetor;
    vetor = findRelativeRanks(score, 5, returnSize);
    for(int i=0; i<5; i++){
        printf("%s\n", vetor[i]);
    }
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    int *vetor = (int *)malloc(scoreSize * sizeof(int));
    *vetor = score[0];
    int i=1, j, temp;

    while(i<scoreSize){
        *(vetor + i) = score[i];
        j = i;

        while(j> 0 && *(vetor+j)>*(vetor+j-1)){
            temp = *(vetor+j-1);
            *(vetor+j-1) = *(vetor+j);
            *(vetor+j) = temp;
            j--;
        }

        i++;
    }

    char *gold = "Gold Medal";
    char *silver = "Silver Medal";
    char *bronze = "Bronze Medal";
    char **vetor_palavra = malloc(scoreSize * sizeof(char *));

    for(i = 0; i<scoreSize; i++){
        j=0;
        while (j<scoreSize && score[i] != *(vetor+j)){
            j++;
        }
        if(j==0){
            vetor_palavra[i] = malloc(sizeof(gold));
            vetor_palavra[i] = gold;

        }else if(j==1){
            vetor_palavra[i] = malloc(sizeof(silver));
            vetor_palavra[i] = silver;
        
        }else if(j==2){
            vetor_palavra[i] = malloc(sizeof(bronze));
            vetor_palavra[i] = bronze;
           
        }else {
            vetor_palavra[i] = malloc(j * sizeof(char));
            sprintf(vetor_palavra[i], "%d", j+1);
         
        }
    }
    
    *returnSize = scoreSize;
    return vetor_palavra;
}