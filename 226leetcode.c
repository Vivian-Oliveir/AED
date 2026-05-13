//Given the root of a binary tree, invert the tree, and return its root.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Inicializa( struct TreeNode** root );
void Insere( int x, struct TreeNode** root );
void Lista( struct TreeNode* root );
void Liberar( struct TreeNode** root );
struct TreeNode* invertTree( struct TreeNode* root );

int main(){
    struct TreeNode *raiz;
    Inicializa( &raiz );
    Insere( 9, &raiz );
    Insere( 7, &raiz );
    Insere( 10, &raiz );
    Insere( 21, &raiz );
    Lista( raiz );
    invertTree( raiz );
    printf( "Árvore invertida:\n" );
    Lista( raiz );
    Liberar( &raiz );
    return 0;
}

struct TreeNode* invertTree( struct TreeNode* root ) { //função leetcode
    struct TreeNode *temp;
    if( root == NULL ) {
        return NULL;
    }
    temp = root->right;
    root->right = root->left;
    root->left = temp;
    invertTree( root->right );
    invertTree( root->left );
    return root;
}

void Insere( int x, struct TreeNode** root ) {
    if( *root == NULL ) {
        *root = ( struct TreeNode* )malloc( sizeof( struct TreeNode ));
        (*root)->val = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if( x > (*root)->val ) {
        Insere( x, &(*root)->right );
        return;
    } else if( x < (*root)->val ) {
        Insere( x, &(*root)->left );
        return;
    } else {
        return;
    }
}

void Inicializa( struct TreeNode** root ) {
    *root = NULL;
}

void Lista( struct TreeNode* root ) {
    if( root == NULL ) {
        return;
    }

    Lista( root->left );
    printf( "%d\n", root->val );
    Lista( root->right );
}

void Liberar( struct TreeNode** root ) {
    if( *root == NULL ) {
        return;
    }

    Liberar( &(*root)->left );
    Liberar( &(*root)->right );
    free( *root );
    *root = NULL;
}