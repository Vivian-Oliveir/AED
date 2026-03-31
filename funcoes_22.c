//Crie uma funcao que receba como parametro um valor inteiro e gere como saida n linhas
//com pontos de exclamacao, conforme o exemplo abaixo (para n = 5):

#include <stdio.h>

void imprime_linhas(int n);

int main(){
    int n;
    
    printf("Digite o número de linhas: ");
    scanf("%d",&n);
    imprime_linhas(n);

    return 0;
}

void imprime_linhas(int n){
    int i, j;
    
    for(i=0;i<(n+1);i++){
        for(j=0;j<i;j++){
            printf("\t!");
        }
        printf("\n");
    }
}