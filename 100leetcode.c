//Given the roots of two binary trees p and q, write a function to check if 
//they are the same or not.
//Two binary trees are considered the same if they are structurally identical, 
//and the nodes have the same value.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode * Apontador;

void Insere( int val, Apontador *root );
void Inicializa( Apontador *root );
void Lista( Apontador root );
bool isSameTree( struct TreeNode* p, struct TreeNode* q );

int main() {
    Apontador raiz1, raiz2;
    Inicializa( &raiz1 );
    Inicializa( &raiz2 );

    Insere( 3, &raiz1 );
    Insere( 9, &raiz1 );
    Insere( 20, &raiz1 );
    Insere( 15, &raiz1 );
    Insere( 7, &raiz1 );

    Lista( raiz1 );
    printf( "\n" );
    Insere( 3, &raiz2 );
    Insere( 9, &raiz2 );
    Insere( 2, &raiz2 );
    Insere( 15, &raiz2 );
    Insere( 7, &raiz2 );

    Lista( raiz2 );
    if( isSameTree( raiz1, raiz2 ) ) {
        printf( "São a mesma árvore" );
    } else {
        printf( "Não são a mesma árvore" );
    }

}

bool isSameTree( struct TreeNode* p, struct TreeNode* q ) { //função leetcode
    bool retorno1, retorno2;
    if( ( p == NULL ) && ( q == NULL ) ) {
        return true;
    } else if ( (( p == NULL ) && ( q != NULL )) || 
    (( p != NULL ) && ( q == NULL ))) {
        return false;
    } else if( p->val != q->val ) {
        return false;
    }

    retorno1 = isSameTree( p->left, q->left );
    retorno2 = isSameTree( p->right, q->right );

    if( retorno1 && retorno2 ) {
        retorno1 = true;
    } else {
        retorno1 = false;
    }
    return retorno1;
}

void Inicializa( Apontador *root ) {
    *root = NULL;
}

void Insere( int val, Apontador *root ) {
    if( *root == NULL ) {
        *root = ( Apontador )malloc( sizeof( struct TreeNode ) );
        (*root)->val = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if( val < (*root)->val ) {
        Insere( val, &(*root)->left );
        return;
    } else if( val > (*root)->val ) {
        Insere( val, &(*root)->right );
        return;
    } else {
        return;
    }
}

void Lista( Apontador root ) {
    if( root == NULL ) {
        return;
    }
    Lista( root->left );
    printf( "%d\n", root->val );
    Lista( root->right );
}