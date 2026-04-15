//Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, 2 is written as II in Roman numeral, just two ones added together. 
//12 is written as XII, which is simply X + II. The number 27 is written as XXVII, 
//which is XX + V + II.
//Roman numerals are usually written largest to smallest from left to right. However, 
//the numeral for four is not IIII. Instead, the number four is written as IV. Because the 
//one is before the five we subtract it making four. The same principle applies to the number 
//nine, which is written as IX. There are six instances where subtraction is used:
//I can be placed before V (5) and X (10) to make 4 and 9. 
//X can be placed before L (50) and C (100) to make 40 and 90. 
//C can be placed before D (500) and M (1000) to make 400 and 900.
//Given a roman numeral, convert it to an integer.
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
    char c;
    int cont=0, I=0, V=0, X=0, L=0, C=0, D=0, M=0, resultado = 0;
    while(*(s+cont) != '\0'){
        while(*(s+cont)=='M'){
            M += 1000;
            cont++;
        }
        while(*(s+cont)=='D'){
            D += 500;
            cont++;
        }
        while(*(s+cont)=='C'){
            if(*(s+(cont+1))=='D'){
                C += 400;
                cont += 2;
                break;
            }
            if(*(s+(cont+1))=='M'){
                C += 900;
                cont += 2;
                break;
            }
            C += 100;
            cont++;
        }
        while(*(s+cont)=='L'){
            L += 50;
            cont++;
        }
        while(*(s+cont)=='X'){
            if(*(s+(cont+1))=='L'){
                X += 40;
                cont += 2;
                break;
            }
            if(*(s+(cont+1))=='C'){
                X += 90;
                cont += 2;
                break;
            }
            X += 10;
            cont++;
        }
        while(*(s+cont)=='V'){
            V += 5;
            cont++;
        }
        while(*(s+cont)=='I'){
            if(*(s+(cont+1))=='V'){
                I += 4;
                cont += 2;
                break;
            }
            if(*(s+(cont+1))=='X'){
                X += 9;
                cont += 2;
                break;
            }
            I++;
            cont++;
        }
    }

    resultado = I + V + X + L + C + D + M;
    return resultado;
}