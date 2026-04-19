//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
//determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char* s);

int main(){
    char *str;
    str = (char *)malloc(10000 * sizeof(char));

    printf("Digite: ");
    scanf("%[^\n]",str);
    //printf("%s",str);

    if(isValid(str)){
        printf("Entrada válida.");
    }else{
        printf("Entrada inválida.");
    }

}

bool isValid(char* s) {
    int i=0, j, c=0;
    for(i=0;*(s+i)!='\0';i++){
        if(*(s+i)!='(' && *(s+i)!=')' && *(s+i)!='[' && *(s+i)!=']' &&
        *(s+i)!='{' && *(s+i)!='}'){
            return false;
        }
    }

    i=0;

    while(1){
        if((*(s+i)=='(' && *(s+i+1)==')') || (*(s+i)=='[' && *(s+i+1)==']') ||
        (*(s+i)=='{' && *(s+i+1)=='}')){
            c = i;
            i+=2;
            if(*(s+c+2)=='\0'){
                return true;
            }
        }else if((*(s+i)=='(' && *(s+i+1)!=')') || (*(s+i)=='[' && *(s+i+1)!=']') ||
        (*(s+i)=='{' && *(s+i+1)!='}')){
            j = i+1;
            while((*(s+j) != '\0') && ((*(s+i)=='(' && *(s+j)!=')') || (*(s+i)=='[' && *(s+j)!=']') ||
            (*(s+i)=='{' && *(s+j)!='}'))){
                j++;
            }
            if((*(s+j) == '\0') && (*(s+i)=='(' && *(s+j)!=')') || (*(s+i)=='[' && *(s+j)!=']') ||
            (*(s+i)=='{' && *(s+j)!='}')){
                return false;
            }
            c = j;
            i++;
            j--;
            if(i==j){
                return false;
            }
            while(i<j){
                if((*(s+i)=='(' && *(s+j)!=')') || (*(s+i)=='[' && *(s+j)!=']') ||
            (*(s+i)=='{' && *(s+j)!='}')){
                return false;
                }else if((*(s+i)==')') || (*(s+i)==']') ||
                (*(s+i)=='}')){
                    return false;
                }else{
                    i++;
                    j--;
                }
            }
            if(*(s+c+1)=='\0'){
                return true;
            }   
        }else if((*(s+i)==')') || (*(s+i)==']') ||
        (*(s+i)=='}')){
            return false;
        }
    }
}