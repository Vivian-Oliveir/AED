//Crie um programa que receba tres valores (obrigatoriamente maiores que zero), representando 
//as medidas dos tres lados de um triangulo. Elabore funcoes para:

//(a) Determinar se eles lados formam um triangulo, sabendo que:
//O comprimento de cada lado de um triangulo e menor do que a soma dos outros
//dois lados.

//(b) Determinar e mostrar o tipo de triangulo, caso as medidas formem um triangulo.
//Sendo que:
//Chama-se equilatero o triangulo que tem tres lados iguais. 
//Denominam-se isosceles o triangulo que tem o comprimento de dois lados iguais.
//Recebe o nome de escaleno o triangulo que tem os tres lados diferentes. 

#include <stdio.h>
#include <stdlib.h>

int e_triangulo(float a, float b, float c);
void tipo_triangulo(float a, float b, float c);

int main(){
    float lado_a, lado_b, lado_c;
    int op;

    printf("Digite as medidas dos lados do triângulo: ");
    scanf("%f%f%f",&lado_a, &lado_b, &lado_c);

    while(lado_a<=0 || lado_b<=0 || lado_c<=0){
        printf("Valor inválido, digite valores maiores que zero.\n");
        printf("Digite as medidas dos lados do triângulo: ");
        scanf("%f%f%f",&lado_a, &lado_b, &lado_c);
    }

    op = e_triangulo(lado_a, lado_b, lado_c);
    if(op==1){
        tipo_triangulo(lado_a, lado_b, lado_c);
    }

    return 0;
}

int e_triangulo(float a, float b, float c){
    if(a<(b+c) && b<(a+c) && c<(a+b)){
        printf("É triângulo.\n");
        return 1;
    }else{
        printf("Não é triângulo.\n");
        return 0;
    }
}

void tipo_triangulo(float a, float b, float c){
    if(a==b && a==c){
        printf("O triângulo é equilátero.\n");
    }else if((a==b) || (a==c) || (b==c)){
        printf("O triângulo é isóceles.\n");
    }else{
        printf("O triângulo é escaleno.\n");
    }
}