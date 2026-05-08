//malloc
//realloc(pBuffer, tamanho_novo) 
// int menu, int contador;
//void *novoBuffer = malloc();
//memcpy
//free(pBuffer);
//pBuffer = novoBuffer;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(void *pBuffer);
void adicionarPessoa(void *pBuffer);
void removerPessoa(void *pBuffer);
void buscarPessoa(void *pBuffer);
void listarTodos(void *pBuffer);

int main(){
    void *pBuffer;
    pBuffer = malloc(2 * (sizeof(int))); //menu e contador de pessoas
    *((int *)pBuffer) = 0; //casting
    *((int *)pBuffer+1) = 0;

    do{
        menu(pBuffer);
        printf("\n%d\n",*(int*)pBuffer);
        switch(*(int *)pBuffer){
            case 1:
                adicionarPessoa(pBuffer);
                break;
            case 2:
                removerPessoa(pBuffer);
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
    }while(*(int*)pBuffer != 5);
    
    return 0;
}

void menu(void *pBuffer){
    printf("1. Adicionar pessoa\n");
    printf("2. Remover pessoa\n");
    printf("3. Buscar pessoa\n");
    printf("4. Listar todos\n");
    printf("Digite qual operação deseja realizar: ");
    scanf("%d",(int*)pBuffer);
    getchar();

    if(*(int*)pBuffer<1 || *(int*)pBuffer>5){
        printf("Operação inválida.\n");
        printf("Digite qual operação deseja realizar: ");
        scanf("%d",(int*)pBuffer);
        getchar();
    }
}

void adicionarPessoa(void *pBuffer){
    void *temp;
    temp = malloc(100 * sizeof(char));

    printf("Digite o nome: ");
    scanf("%99[^\n]",(char*)temp);
    printf("%s\n",(char*)temp);

    pBuffer = realloc(pBuffer, (sizeof(pBuffer) + strlen((char*)temp) + 1));
    strcpy((char*)pBuffer + 2 * sizeof(int), (char*)temp);

    printf("%s\n", (char*)pBuffer + 2 * sizeof(int));
}

void removerPessoa(void *pBuffer){

}

void buscarPessoa(void *pBuffer){

}

void listarTodos(void *pBuffer){

}