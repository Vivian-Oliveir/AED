//int menu, int tamanho, int contadorPessoas, int contadorListar, int tamanhoNovo... (nomes, idades, emails)
//    0   ,      1     ,         2          ,         3          ,        4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(void *pBuffer);
void adicionarPessoa(void **pBuffer);
void removerPessoa(void **pBuffer);
void buscarPessoa(void *pBuffer);
void listarTodos(void *pBuffer);

int main(){
    void *pBuffer;
    pBuffer = malloc(5 * (sizeof(int))); //menu, tamanho, contadorPessoas, contadorListar, tamanhoNovo
    *((int *)pBuffer) = 0; //menu
    *((int *)pBuffer+1) = 5 * sizeof(int); //tamanho inicial
    *((int *)pBuffer+2) = 0; //contador de pessoas
    *((int *)pBuffer+3) = 1; //contador que eu vou usar p listarTodos
    *((int *)pBuffer+4) = *((int *)pBuffer+1); //tamanhoNovo pra quando eu for remover algm

    while(1){
        menu(pBuffer);
        switch(*(int *)pBuffer){
            case 1:
                adicionarPessoa(&pBuffer);
                break;
            case 2:
                removerPessoa(&pBuffer);
                break;
            case 3:
                buscarPessoa(pBuffer);
                break;
            case 4:
                listarTodos(pBuffer);
                break;
            case 5:
                free(pBuffer);
                exit(1);
        }
    }
    
    return 0;
}

void menu(void *pBuffer){
    printf("────────── ✦ Agenda ✦ ──────────\n");
    printf("1. Adicionar pessoa\n");
    printf("2. Remover pessoa\n");
    printf("3. Buscar pessoa\n");
    printf("4. Listar todos\n");
    printf("5. Sair\n");
    printf("Digite qual operação deseja realizar: ");
    scanf("%d",(int*)pBuffer);
    getchar();
    printf("────────────────────────────────\n");

    while(*(int*)pBuffer<1 || *(int*)pBuffer>5){
        printf("Operação inválida.\n");
        printf("Digite qual operação deseja realizar: ");
        scanf("%d",(int*)pBuffer);
        getchar();
    }
}

void adicionarPessoa(void **pBuffer){
    void *temp;
    temp = malloc(100 * sizeof(char)); //ponteiro temporário para receber entrada

    printf("Digite o nome: ");
    scanf("%99[^\n]",(char*)temp);
    getchar();
    *pBuffer = realloc(*pBuffer, *(((int*)*pBuffer) + 1) + strlen((char*)temp) + 1); //realocando pBuffer p caber novo nome
    strcpy((char*)*pBuffer + *(((int*)*pBuffer) + 1), (char*)temp); // colocando o nome dps do que tinha sido guardado
    *(((int*)*pBuffer) + 1) += strlen((char*)temp) + 1; //aumentando o tamanho guardado

    printf("Digite a idade: ");
    *pBuffer = realloc(*pBuffer, *(((int*)*pBuffer) + 1) + sizeof(int)); //realocando pBuffer p caber nova idade
    scanf("%d", (int*)((char*)*pBuffer + *(((int*)*pBuffer) + 1))); // colocando a idade dps do que tinha sido guardado
    getchar();
    *(((int*)*pBuffer) + 1) += sizeof(int); //aumentando o tamanho guardado

    printf("Digite o email: ");
    scanf("%99[^\n]",(char*)temp);
    getchar();
    *pBuffer = realloc(*pBuffer, *(((int*)*pBuffer) + 1) + strlen((char*)temp) + 1); //realocando pBuffer p caber novo email
    strcpy((char*)*pBuffer + *(((int*)*pBuffer) + 1), (char*)temp); // colocando o email dps do que tinha sido guardado
    *(((int*)*pBuffer) + 1) += strlen((char*)temp) + 1; //aumentando o tamanho guardado

    *((int *)*pBuffer+2) += 1; //aumentando contador de pessoas

    free(temp);
}

void removerPessoa(void **pBuffer){
    void *temp;
    temp = malloc(100*sizeof(char));
    printf("Digite o nome da pessoa que deseja remover: ");
    scanf("%99[^\n]",(char*)temp);
    getchar(); //lendo o nome buscado p remover

    char *fim, *rem;
    char *comeco = (char*)*pBuffer + 5 * sizeof(int); //ponteiro p dps dos ints

    while(*((int *)*pBuffer+3) <= *((int *)*pBuffer+2)){ //contadorListar <= contadorPessoas
        if(strcmp(temp, comeco) == 0){
            rem = comeco;
            fim = comeco;
            fim += strlen(fim) + 1; //pulando o nome e o \0
            fim += sizeof(int); //pulando idade
            fim += strlen(fim) + 1; //pulando o email e o \0
            break;
        }else{
            comeco += strlen(comeco) + 1; //pulando o nome e o \0
            comeco += sizeof(int); //pulando idade
            comeco += strlen(comeco) + 1; //pulando o email e o \0
            *((int *)*pBuffer+3) += 1; //próxima pessoa
        }
    }

    if(*((int *)*pBuffer+3) > *((int *)*pBuffer+2)){
        printf("Nome não encontrado.\n");
    }else{
        *(((int*)*pBuffer) + 4) = *(((int*)*pBuffer) + 1);

        *(((int*)*pBuffer) + 4) -= (strlen(rem) + 1); //tirando o tamanho do nome de tamanhoNovo
        rem += strlen(rem) + 1; //pulando o nome e o \0
        *(((int*)*pBuffer) + 4) -= sizeof(int); //tirando o tamanho da idade
        rem += sizeof(int); //pulando idade
        *(((int*)*pBuffer) + 4) -= (strlen(rem) + 1); //tirando o tamanho do email

        //memmove(de onde eu comeco a copiar, até onde copio, quantos bytes copiar)
        memmove(comeco, fim, *(((int*)*pBuffer) + 1) - (fim - (char*)*pBuffer));
        //*(((int*)*pBuffer) + 1) -> tamanho atual do pBuffer
        //(fim - (char*)pBuffer) calculando de onde começa o pBuffer até o fim da pessoa

        *pBuffer = realloc(*pBuffer, *(((int*)*pBuffer) + 4)); //realocando pBuffer p tamanhoNovo
        *(((int*)*pBuffer) + 1) = *(((int*)*pBuffer) + 4); //atualizando tamanho atual
        *((int *)*pBuffer+2) -= 1; //diminuindo contadorPessoas
        printf("Nome removido.\n");
    }

    *((int *)*pBuffer+3) = 1; //contadorListar = 1;
    free(temp);
}

void buscarPessoa(void *pBuffer){
    void *temp;
    temp = malloc(100*sizeof(char));
    printf("Digite o nome que está buscando: ");
    scanf("%99[^\n]",(char*)temp);
    getchar(); //lendo o nome buscado

    char *inf = (char*)pBuffer + 5 * sizeof(int);

    while(*((int *)pBuffer+3) <= *((int *)pBuffer+2)){ //contadorListar <= contadorPessoas
        if(strcmp(temp, inf) == 0){
            printf("Nome: %s\n", inf);
            inf += strlen(inf) + 1; //pulando o nome q eu li e o \0 

            printf("Idade: %d\n", *(int*)inf);
            inf += sizeof(int); //pulando idade

            printf("Email: %s\n", inf);
            break; 
            
        }else{
            inf += strlen(inf) + 1; //pulando o nome e o \0 que nn eram da pessoa procurada
            inf += sizeof(int); //pulando idade que nn era da pessoa procurada
            inf += strlen(inf) + 1; //pulando o email e o \0 q nn era da pessoa procurada 
            *((int *)pBuffer+3) += 1; //colocando o contador pra próxima pessoa
        }
    }  

    if(*((int *)pBuffer+3) > *((int *)pBuffer+2)){
        printf("Nome não encontrado.\n");
    }

    *((int *)pBuffer+3) = 1; //contadorListar = 1
    free(temp);
}

void listarTodos(void *pBuffer){
    char *inf = (char*)pBuffer + 5 * sizeof(int);
    while(*((int *)pBuffer+3) <= *((int *)pBuffer+2)){ //contadorListar <= contadorPessoas

        printf("Pessoa %d ───────────────────── ✦\n",*((int *)pBuffer+3));
        printf("Nome: %s\n", inf);
        inf += strlen(inf) + 1; //pulando o nome q eu li e o \0 

        printf("Idade: %d\n", *(int*)inf);
        inf += sizeof(int); //pulando idade

        printf("Email: %s\n", inf);
        inf += strlen(inf) + 1; //pulando o email q eu li e o \0 
        
        *((int *)pBuffer+3) += 1; //colocando o contador pra próxima pessoa
        
    }  

    *((int *)pBuffer+3) = 1; //Reinicializando o contadorListar pra próxima vez que for listar
}