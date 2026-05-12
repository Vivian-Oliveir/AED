#include <stdio.h>

int mySqrt( int x );
int acharTopo( int x, int topo );
int acharMaisProximo( int x, int piso, int topo );

int main() {
    int x = 144, raiz;
    raiz = mySqrt( x );
    printf( "%d", raiz );
    return 0;
}

int mySqrt( int x ) {
    long int topo, piso, maisproximo;
    topo = x / 2;
    while( topo > 46000 ) { //para não dar erro em números muito grandes
        topo = topo / 2;
    }
    
    if( topo * topo > x ) {
        topo = acharTopo( x, topo );
        piso = topo / 2;
        maisproximo = acharMaisProximo( x, piso, topo );

    } else if( x < 88000 && x * x == x ) {
        return x;

    } else {
        piso = topo;
        topo = topo * 2;
        while( topo > 48000 ) {
            topo = topo - 1000;
        }
        while( topo > 46340 ) {
            topo--;
        }
        maisproximo = acharMaisProximo( x, piso, topo );
    }

    return maisproximo;
}

int acharTopo( int x, int topo ) {
    topo = topo / 2;

    if( topo * topo > x ) {
        topo = acharTopo( x, topo );
    } else if( topo * topo < x ) {
        return topo * 2;
    } else {
        return topo;
    }
    return topo;
}

int acharMaisProximo( int x, int piso, int topo ) {
    int meio;
    if( topo - piso == 1 ) {
        if( topo * topo <= x ) {
            return topo;
        }else {
            return piso;
        }
    }
    meio = piso + ( topo - piso ) / 2;
    if( meio * meio > x ) {
        meio = acharMaisProximo( x, piso, meio );
    } else if( meio * meio < x ) {
        meio = acharMaisProximo( x, meio, topo );
    }
    return meio;
}