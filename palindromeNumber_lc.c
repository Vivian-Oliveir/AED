//Given an integer x, return true if x is a palindrome, and false otherwise.
//Example 1:
//Input: x = 121
//Output: true
//Explanation: 121 reads as 121 from left to right and from right to left.
//Example 2:
//Input: x = -121
//Output: false
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main(){
    int x;
    printf("Digite um número: ");
    scanf("%d",&x);

    if(isPalindrome(x)){
        printf("O número é um palíndromo.");
    }else{
        printf("O número não é um palíndromo.");
    }

    return 0;
}

bool isPalindrome(int x){
    char *number;
    number = (char *)malloc(200 * sizeof(char));

    snprintf(number, 200, "%d", x);
    int i=0, j;
    for(j=0;*(number+j)!='\0';j++);
    j--;

    while(*(number+i) == *(number+j) && i<j){
        i++;
        j--;
    }
    
    if(i==j || i>j){
        return true;
    }else{
        return false;
    }
}