//Vivian Rodrigues de Oliveira
//int menu, int tamanhoAtual, int contadorPessoas, int contadorListar/Remover, int tamanhoNovo... (nomes, idades, emails)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu( void *pBuffer );
void adicionarPessoa( void **pBuffer );
void removerPessoa( void **pBuffer );
void buscarPessoa( void *pBuffer );
void listarTodos( void *pBuffer );

int main() {
    void *pBuffer;
    pBuffer = malloc( 5 * ( sizeof( int ) ) ); 
    *( ( int * )pBuffer ) = 0; //menu
    *( ( int * )pBuffer + 1 ) = 5 * sizeof( int ); //tamanhoAtual
    *( ( int * )pBuffer + 2 ) = 0; //contadorPessoas
    *( ( int * )pBuffer + 3 ) = 1; //contadorListar/Remover
    *( ( int * )pBuffer + 4 ) = *( ( int * )pBuffer + 1 ); //tamanhoNovo

    while( 1 ) {
        menu( pBuffer );
        switch( *( int * )pBuffer ) {
            case 1:
                adicionarPessoa( &pBuffer );
                break;
            case 2:
                removerPessoa( &pBuffer );
                break;
            case 3:
                buscarPessoa( pBuffer );
                break;
            case 4:
                listarTodos( pBuffer );
                break;
            case 5:
                free( pBuffer );
                exit( 1 );
        }
    }
    
    return 0;
}

void menu( void *pBuffer ) {
    printf( "────────── ✦ Agenda ✦ ──────────\n" );
    printf( "1. Adicionar pessoa\n" );
    printf( "2. Remover pessoa\n" );
    printf( "3. Buscar pessoa\n" );
    printf( "4. Listar todos\n" );
    printf( "5. Sair\n" );
    printf( "Digite qual operação deseja realizar: " );
    scanf( "%d", ( int* )pBuffer );
    getchar();
    printf( "────────────────────────────────\n" );

    while( *( int* )pBuffer < 1 || *( int* )pBuffer > 5 ) {
        printf( "Operação inválida.\n" );
        printf( "Digite qual operação deseja realizar: " );
        scanf( "%d", ( int* )pBuffer );
        getchar();
    }
}

void adicionarPessoa( void **pBuffer ) {
    void *temp;
    temp = malloc( 100 * sizeof( char ) ); 

    printf( "Digite o nome: " );
    scanf( "%99[^\n]", ( char* )temp );
    getchar();
    *pBuffer = realloc( *pBuffer, *((( int* )*pBuffer ) + 1 ) + strlen(( char* )temp ) + 1 );
    strcpy(( char* )*pBuffer + *((( int* )*pBuffer ) + 1 ), ( char* )temp );
    *((( int* )*pBuffer ) + 1 ) += strlen(( char* )temp ) + 1; //tamanhoAtual

    printf( "Digite a idade: " );
    *pBuffer = realloc( *pBuffer, *((( int* )*pBuffer ) + 1 ) + sizeof( int ) );
    scanf( "%d", ( int* )(( char* )*pBuffer + *((( int* )*pBuffer ) + 1 )));
    getchar();
    *((( int* )*pBuffer ) + 1 ) += sizeof( int ); //tamanhoAtual

    printf( "Digite o email: " );
    scanf( "%99[^\n]", ( char* )temp );
    getchar();
    *pBuffer = realloc( *pBuffer, *((( int* )*pBuffer ) + 1 ) + strlen(( char* )temp ) + 1 ); 
    strcpy(( char* )*pBuffer + *((( int* )*pBuffer ) + 1 ), ( char* )temp ); 
    *((( int* )*pBuffer ) + 1 ) += strlen(( char* )temp ) + 1; //tamanhoAtual

    *(( int * )*pBuffer + 2 ) += 1; //contadorPessoas

    free( temp );
}

void removerPessoa( void **pBuffer ) {
    void *temp;
    temp = malloc( 100 * sizeof( char ));
    printf( "Digite o nome da pessoa que deseja remover: " );
    scanf( "%99[^\n]", ( char* )temp );
    getchar(); 

    char *fim, *rem;
    char *comeco = ( char* )*pBuffer + 5 * sizeof( int ); //ponteiro para o primeiro nome

    while( *(( int * )*pBuffer + 3 ) <= *(( int * )*pBuffer + 2 )) { //contadorListar/Remover <= contadorPessoas
        if( strcmp( temp, comeco ) == 0 ) {
            rem = comeco;
            fim = comeco;
            fim += strlen( fim ) + 1;
            fim += sizeof( int ); 
            fim += strlen( fim ) + 1;
            break;
        } else {
            comeco += strlen( comeco ) + 1;
            comeco += sizeof( int ); 
            comeco += strlen( comeco ) + 1; 
            *(( int * )*pBuffer + 3 ) += 1; //contadorListar/Remover++
        }
    }

    if( *(( int * )*pBuffer + 3 ) > *(( int * )*pBuffer + 2 )) {
        printf( "Nome não encontrado.\n" );
    } else {
        *((( int* )*pBuffer ) + 4 ) = *((( int* )*pBuffer ) + 1 ); //tamanhoNovo = tamanhoAtual

        *((( int* )*pBuffer ) + 4 ) -= ( strlen( rem ) + 1 );
        rem += strlen( rem ) + 1;
        *((( int* )*pBuffer ) + 4 ) -= sizeof( int );
        rem += sizeof( int );
        *((( int* )*pBuffer ) + 4 ) -= ( strlen( rem ) + 1 );

        memmove( comeco, fim, *((( int* )*pBuffer ) + 1 ) - ( fim - ( char* )*pBuffer ));
        //*(((int*)*pBuffer) + 1) -> tamanho atual do pBuffer
        //(fim - (char*)pBuffer) calculando de onde começa o pBuffer até o fim da pessoa

        *pBuffer = realloc( *pBuffer, *((( int* )*pBuffer ) + 4 ));
        *((( int* )*pBuffer ) + 1 ) = *((( int* )*pBuffer ) + 4 ); //tamanhoAtual = tamanhoNovo
        *(( int * )*pBuffer + 2 ) -= 1; //contadorPessoas--
        printf( "Nome removido.\n" );
    }

    *(( int * )*pBuffer + 3 ) = 1; //reinicializando contadorListar/Remover
    free( temp );
}

void buscarPessoa( void *pBuffer ) {
    void *temp;
    temp = malloc( 100 * sizeof( char ));
    printf( "Digite o nome que está buscando: " );
    scanf( "%99[^\n]", ( char* )temp );
    getchar();

    char *inf = ( char* )pBuffer + 5 * sizeof( int );

    while( *(( int * )pBuffer + 3 ) <= *(( int * )pBuffer + 2 )) { //contadorListar/Remover <= contadorPessoas
        if( strcmp( temp, inf ) == 0 ) {
            printf( "Nome: %s\n", inf );
            inf += strlen( inf ) + 1; 

            printf( "Idade: %d\n", *( int* )inf );
            inf += sizeof( int ); 

            printf( "Email: %s\n", inf );
            break; 
            
        }else{
            inf += strlen( inf ) + 1; 
            inf += sizeof( int );
            inf += strlen( inf ) + 1; 
            *(( int * )pBuffer + 3 ) += 1;
        }
    }  

    if( *(( int * )pBuffer + 3 ) > *(( int * )pBuffer + 2 )) { //contadorListar/Remover = contadorPessoas 
        printf( "Nome não encontrado.\n" );
    }

    *(( int * )pBuffer + 3 ) = 1; //Reincializando contadorListar/Remover
    free( temp );
}

void listarTodos( void *pBuffer ) {
    char *inf = ( char* )pBuffer + 5 * sizeof( int );
    while( *(( int * )pBuffer + 3 ) <= *(( int * )pBuffer + 2 )) { 
        printf( "Pessoa %d ───────────────────── ✦\n", *(( int * )pBuffer + 3 ));
        printf( "Nome: %s\n", inf );
        inf += strlen( inf ) + 1; 

        printf( "Idade: %d\n", *( int* )inf );
        inf += sizeof( int ); 

        printf( "Email: %s\n", inf );
        inf += strlen( inf ) + 1; 
        
        *(( int * )pBuffer + 3 ) += 1; 
    }  

    *(( int * )pBuffer + 3 ) = 1; //Reinicializando contadorListar/Remover
}