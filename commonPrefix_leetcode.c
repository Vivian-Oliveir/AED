//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string "".
//Example 1:
//Input: strs = ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//Input: strs = ["dog","racecar","car"]
//Output: ""
//Constraints:
//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] consists of only lowercase English letters if it is non-empty.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main(){
    char **strs, *prefix;
    int op = 0, i=1, j=0;
    strs = (char **)malloc(i * sizeof(char *));

    do{
        strs[j] = (char *)malloc(200 *sizeof(char));
        printf("Digite uma palavra: ");
        scanf("%s",strs[j]);
        getchar();
        i++;
        strs = realloc(strs, i * sizeof(char *));
        printf("Deseja digitar uma nova palavra?\n1. Sim\n2. Não\n");
        scanf("%d",&op);
        j++;
    }while(op==1);

    for(i=0; i<j; i++){
        printf("%s\n",strs[i]);
    }

    prefix = longestCommonPrefix(strs, j);
    printf("Prefixo comum mais longo: %s",prefix);
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    char *prefix;
    prefix = (char *)malloc(200 * sizeof(char));

    int i=0, j=0, k=0;
    while(1){
        i=0;
        while(i+1 < strsSize && strs[i][j] != '\0' && strs[i+1][j] != '\0' &&
             strs[i][j] == strs[i+1][j]){
            i++;
        }
        if(i+1 == strsSize && strs[i][j] != '\0'){
            *(prefix + k) = strs[i][j];
            k++;
        }else{
            *(prefix + k) = '\0';
            break;
        }
        j++;
    }

    return prefix;
}