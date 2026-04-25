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
    int i, j, aceito = 0;
    char aceitos[] = "()[]{}", last, aberto_m, fechado_m, continuar;
    char abertos[] = "([{", fechados[] = ")]}";

    for( i = 0; *(s+i) != '\0'; i++ ) {
        aceito = 0;

        for ( j = 0; j < 6; j++) {
            if( *(s+i) == aceitos[j] ){
                aceito = 1;
                break;
            }
        }

        if( aceito == 0 ) {
            return false;
        }
    } //ver se todos os caracteres são válidos

    if( *s == ']' || *s == '}' || *s == ')'){
        return false;
    }

    for( i = 0; *(s+i) != '\0'; i++ ) {
        aceito = 0;
        continuar = i;
        for ( j = 0; j < 3; j++ ) {
            if( *(s+i) == abertos[j] ) {
                aceito = 1;
                aberto_m = i;

                while ( *(s+i) != '\0' && *(s+i) != fechados[j] ) {
                    i++;
                }
                if( *(s+i) == '\0' ){
                    return false;
                }

                fechado_m = i;
                continuar = fechado_m + 1;

                while( aberto_m < fechado_m && (fechado_m - aberto_m > 1)) {
                    j = 0;
                    aberto_m++;
                    fechado_m--;
                    for ( j = 0; j < 3; j++ ) {
                        if( *(s+aberto_m) == abertos[j] && *(s+fechado_m) != fechados[j] ){
                            return false;
                        }
                    }
                }

                if( fechado_m - aberto_m == 1 ) {
                    return false;
                }
                break;
            } 
        }
        if ( aceito == 0 ){
            return false;
        }
        i = continuar;
    }

    return true;
}