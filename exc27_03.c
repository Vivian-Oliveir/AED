#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu(void);
char* adicionar(char *lista);
char* remover(char *lista);
void listar(char *lista);

int main(){
    int op;
    char *lista = NULL;

    while(1){
        op = menu();
        switch(op){
            case 1:
                lista = adicionar(lista);
                break;
            case 2:
                lista = remover(lista);
                break;
            case 3:
                listar(lista);
                break;
            case 4:
                exit(1);
            default:
                printf("Entrada inválida.\n");
                break;
        }
    }

    return 0;
}

int menu(void){
    int op=0;
    printf("\n1. Adicionar\n2. Remover\n3. Listar\n4. Sair\nDigite sua escolha: ");
    scanf("%d",&op);
    getchar();
    return op;
}

char* adicionar(char *lista){
    char c;
    int i;

    if(lista == NULL){
        i=0;
    }else{
        for(i=0;lista[i]!='\0';i++);
    }

    printf("Digite o nome: ");
    while((c = getchar()) != '\n'){
        lista = realloc(lista, i+3);
        lista[i] = c;
        i++;
    }
    lista[i] = '\n';
    lista[i+1] = '\0';

    return lista;
}

char* remover(char *lista){
    char proc[80];
    int i, j, cmc, fim, encontrado = 0;

    printf("Digite o nome que deseja remover: ");
    fgets(proc, 80, stdin);

    for(i=0;lista[i]!='\0';i++){
        j=0;
        if(lista[i] == proc[j]){
            cmc = i;
            while(proc[j]!='\0' && lista[i]==proc[j]){
                j++;
                i++;
            }
            fim = i;
        }
        if((fim-cmc)==strlen(proc)){
            encontrado = 1;
            break;
        }
    }

    if(encontrado == 0){
        printf("Nome não encontrado.\n");
    }else{
        i=0;
        while(1){
            lista[cmc+i] = lista[fim+i];
            if(lista[cmc+i] == '\0'){
                break;
            }
            i++;
        }
        lista = realloc(lista, (strlen(lista) + 1));
    }

    return lista;
}

void listar(char *lista){
    printf("%s",lista);
}