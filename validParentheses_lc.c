//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
//determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid( char* s );

int main() {
    char *str;
    str = ( char * )malloc( 10000 * sizeof( char ) );

    printf("Digite: ");
    scanf("%[^\n]",str);

    if( isValid( str ) ) {
        printf("Entrada válida.");
    } else {
        printf("Entrada inválida.");
    }

    return 0;
}

bool isValid( char* s ) {
    int i, j, n = 0, l, aceito = 0;

    while( *(s + n) != '\0' ) {
        if( ( *( s + n ) != '(' ) && ( *( s + n ) != ')' ) 
            && ( *( s + n ) != '[' ) && ( *( s + n ) != ']' ) 
            && ( *( s + n ) != '{' ) && ( *( s + n ) != '}' ) ) {
            return false;
        }

        aceito = 0;

        while( *( s + n ) != ']' && *( s + n ) != ')' 
            && *( s + n ) != '}' && *( s + n ) != '\0' ) { 
            n++;
        }

        l = n-1;

        if( l < 0 ) {
            return false;
        }

        while( ( *( s + n ) == ')' && *( s + l ) == '(' ) 
            ||( *( s + n ) == ']' && *( s + l ) == '[' )
            ||( *( s + n ) == '}' && *( s + l ) == '{' ) ) {
                while( *( s + l ) != '\0' ) {
                    *( s + l ) = *( s + n + 1 );
                    if( *( s + l ) == '\0' ) {
                        break;
                    }
                    l++;
                    n++;
                }
                aceito = 1;
                n = 0;
                break;
        }

        if( aceito == 0 ) {
            return false;
        }
    }

    return true;
}