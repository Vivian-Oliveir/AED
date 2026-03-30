//Lista linguagem C - Struct 4
//Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
//conter a matr´ıcula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
//da terceira prova.
//(a) Permita ao usuario entrar com os dados de 5 alunos. 
//(b) Encontre o aluno com maior nota da primeira prova.
//(c) Encontre o aluno com maior media geral. 
//(d) Encontre o aluno com menor media geral 
//(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
//aprovacao.

#include <stdio.h>

struct Alunos{
    int matricula;
    float n1, n2, n3, media;
    char nome[100];
};

int main(){
    struct Alunos alunos[5];
    int i;
    float maior_media, menor_media, maior_n1;

    for(i=0;i<5;i++){
        printf("Digite o nome do aluno %d: ", i+1);
        scanf("%[^\n]", alunos[i].nome);
        printf("Digite a matrícula do aluno: ");
        scanf("%d",&alunos[i].matricula);
        printf("Digite as notas da primeira, segunda e terceira prova, respectivamente: ");
        scanf("%f%f%f",&alunos[i].n1, &alunos[i].n2, &alunos[i].n3);
        getchar();
        alunos[i].media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;
        printf("_____________________________\n");
    }

    maior_media = alunos[0].media;
    menor_media = alunos[0].media;
    maior_n1 = alunos[0].n1;

    for(i=0; i<5; i++){
        if(alunos[i].media > maior_media){
            maior_media = alunos[i].media;
        }
        if(alunos[i].media < menor_media){
            menor_media = alunos[i].media;
        }
        if(alunos[i].n1 > maior_n1){
            maior_n1 = alunos[i].n1;
        }
        if(alunos[i].media > 6){
            printf("%s aprovado(a)!\n", alunos[i].nome);
        }else{
            printf("%s reprovado(a).\n", alunos[i].nome);
        }
    }

    printf("Maior nota na prova 1: %.2f\n", maior_n1);
    printf("Menor média: %.2f\n", menor_media);
    printf("Maior média: %.2f\n", maior_media);

    return 0;
}