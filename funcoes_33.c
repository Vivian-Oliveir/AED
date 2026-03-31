//Faca uma funcao que receba um numero N e retorne a soma dos algarismos de N!. 
//Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e 2 + 4 = 6. 

#include <stdio.h>

int soma_alg(int n);

int main(){
    int n, soma;

    printf("Digite um número: ");
    scanf("%d",&n);
    soma = soma_alg(n);
    printf("Soma dos algarismos de %d!: %d",n, soma);

    return 0;
}

int soma_alg(int n){
    int i, j=10, fat=1, soma=0, alg=0;

    for(i=1;i<=n;i++){
        fat = fat * i;
    }

    printf("Fatorial de %d = %d\n",n, fat);

    while(fat>0){
        alg = fat % j;
        fat -= alg;
        while(alg > 9){
            alg = alg/10;
        }
        soma += alg;
        j *= 10;
    }

    return soma;
}