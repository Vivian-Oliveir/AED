//Given the root of a binary tree, return its maximum depth.
//A binary tree's maximum depth is the number of nodes along the longest path from the root 
//node down to the farthest leaf node.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode * Apontador;

int maxDepth( struct TreeNode* root );
void Insere( int val, Apontador *root );
void Inicializa( Apontador *root );
void Lista( Apontador root );
int Depth( int depth, struct TreeNode *root );

int main() {
    Apontador raiz;
    Inicializa( &raiz );

    Insere( 3, &raiz );
    Insere( 9, &raiz );
    Insere( 20, &raiz );
    Insere( 15, &raiz );
    Insere( 7, &raiz );

    Lista( raiz );

    int retorno;
    retorno = maxDepth( raiz );
    printf( "Depth: %d", retorno );
}

int maxDepth( struct TreeNode *root ) { //função da resposta pro leetcode
    int depth, max;
    depth = 0;
    max = Depth( depth, root );
    return max;
}

int Depth( int depth, struct TreeNode *root ) { //função da resposta pro leetcode
    int depthRight, depthLeft, max;
    depthRight = 0;
    depthLeft = 0;

    if( root == NULL ) {
        return depth;
    }
    depth++;
    depthLeft = Depth( depth, root->left );
    depthRight = Depth( depth, root->right );

    if( depthLeft > depthRight ) {
        max = depthLeft;
    } else {
        max = depthRight;
    }

    return max;
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