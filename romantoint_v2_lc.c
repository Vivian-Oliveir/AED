#include <stdio.h>
#include <stdlib.h>

int romanToInt(char* s);

int main(){
    char *entrada;
    int numero;
    entrada = (char *)malloc(sizeof(char));

    printf("Digite um número romano: ");
    scanf("%s",entrada);
    numero = romanToInt(entrada);

    printf("%s = %d",entrada, numero);
    return 0;
}

int romanToInt(char* s) {
    int cont=0, resultado = 0;
    while(*(s+cont) != '\0'){
        if(*(s+cont) == 'I'){
            if(*(s+cont+1) == 'V'){
                resultado += 4;
                cont += 2;
            }else if(*(s+cont+1) == 'X'){
                resultado += 9;
                cont += 2;
            }else{
                resultado++;
                cont++;
            }
        }else if(*(s+cont) == 'V'){
            resultado += 5;
            cont++;
        }else if(*(s+cont) == 'X'){
            if(*(s+cont+1) == 'L'){
                resultado += 40;
                cont += 2;
            }else if(*(s+cont+1) == 'C'){
                resultado += 90;
                cont += 2;
            }else{
                resultado += 10;
                cont++;
            }
        }else if(*(s+cont) == 'L'){
            resultado += 50;
            cont++;
        }else if(*(s+cont) == 'C'){
            if(*(s+cont+1) == 'D'){
                resultado += 400;
                cont += 2;
            }else if(*(s+cont+1) == 'M'){
                resultado += 900;
                cont += 2;
            }else{
                resultado += 100;
                cont++;
            }
        }else if(*(s+cont) == 'D'){
            resultado += 500;
            cont++;    
        }else if(*(s+cont) == 'M'){
            resultado += 1000;
            cont++;    
        }
    }

    return resultado;
}