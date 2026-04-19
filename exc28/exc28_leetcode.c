#include <stdio.h>
#include <stdlib.h>

int strStr( char* haystack, char* needle );

int main(){
    char *string_original, *string_procurada;
    string_original = (char *)malloc(104 * sizeof(char));
    string_procurada = (char *)malloc(104 * sizeof(char));

    printf("Digite a palavra/frase completa: ");
    scanf("%[^\n]",string_original);
    getchar();

    printf("Digite a palavra que procura: ");
    scanf("%[^\n]",string_procurada);

    int i;
    i = strStr(string_original, string_procurada);
    printf("%d\n",i);
    
    free(string_original);
    free(string_procurada);

    return 0;
}

int strStr( char* haystack, char* needle ) {
    int i = 0, j = 0, index = -1;
    for ( i = 0; *(haystack+i) != '\0'; i++ ) {
        if ( *(haystack+i) == *(needle) ) {
            j = 0;
            index = i;
            while ( *(needle+j) != '\0' && *(haystack+i) != '\0' && 
            *(haystack+i)==*(needle+j) ) {
                i++;
                j++;
            }
            if ( *(needle+j) == '\0' ) {
                return index;
            } else if ( *(haystack+i) == '\0' ) {
                return -1;
            } else {
                i = index;
            }
        }
    }

    return -1;
}