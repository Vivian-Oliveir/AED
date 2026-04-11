//Escreva uma funcao que dado um numero real passado como parametro, retorne a parte
//inteira e a parte fracionaria deste numero. Escreva um programa que chama esta funcao.
//Prototipo: void frac(float num, int* inteiro, float* frac);
#include <stdio.h>
#include <stdlib.h>

void frac(float num, int* inteiro, float* fracionario);

int main(){
    float num, *fracionario;
    int *inteiro;
    fracionario = (float *)malloc(sizeof(float));
    inteiro = (int *)malloc(sizeof(int));
    printf("Digite o número: ");
    scanf("%f",&num);
    frac(num, inteiro, fracionario);
    printf("Parte inteira: %d\nParte fracionária: %.3f",*inteiro,*fracionario);
    return 0;
}


void frac(float num, int* inteiro, float* fracionario){
    *inteiro = (int)num;
    *fracionario = num - *inteiro;
}