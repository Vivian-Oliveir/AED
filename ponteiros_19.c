//Escreva uma funcao que aceita como parametro um array de inteiros com N valores, e
//determina o maior elemento do array e o numero de vezes que este elemento ocorreu
//no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
//8, 6, 15, a funcao deve retorna para o programa que a chamou o valor 15 e o numero 3
//(indicando que o numero 15 ocorreu 3 vezes). A funcao deve ser do tipo void.
#include <stdio.h>
#include <stdlib.h>

void maior_elemento(int *array, int n);

int main(){
    int *array, n=0, i;
    printf("Digite a quantidade de elementos: ");
    scanf("%d",&n);
    array = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("Digite n%d: ",i+1);
        scanf("%d",(array+i));
    }
    maior_elemento(array, n);
    return 0;
}

void maior_elemento(int *array, int n){
    int maior, num_vezes, i;
    maior = *array;
    for(i=0;i<n;i++){
        if(*(array+i) > maior){
            maior = *(array+i);
        }
    }

    for(i=0;i<n;i++){
        if(*(array+i)==maior){
            num_vezes++;
        }
    }

    printf("O maior número é %d e ele aparece %d vezes.\n",maior, num_vezes);
}
