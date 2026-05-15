//232. Implement Queue using Stacks
//Implement a first in first out (FIFO) queue using only two stacks. The implemented 
//queue should support all the functions of a normal queue (push, peek, pop, and empty).
//Implement the MyQueue class:
//void push(int x) Pushes element x to the back of the queue.
//int pop() Removes the element from the front of the queue and returns it.
//int peek() Returns the element at the front of the queue.
//boolean empty() Returns true if the queue is empty, false otherwise.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemento{
    int x;
    struct elemento *prox;
};
typedef struct elemento Elem;
typedef struct elemento* Pilha;

typedef struct {
    Pilha *pilha1;
    Pilha *pilha2;
} MyQueue;

MyQueue* myQueueCreate();
void myQueuePush(MyQueue* obj, int x);
int myQueuePop(MyQueue* obj);
int myQueuePeek(MyQueue* obj);
bool myQueueEmpty(MyQueue* obj);
void myQueueFree(MyQueue* obj);

int main(){
    MyQueue* obj = myQueueCreate();
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    myQueuePush(obj, 3);
    myQueuePush(obj, 4);

    int param_2 = myQueuePop(obj);
    printf("%d ", param_2);

    param_2 = myQueuePop(obj);
    printf("%d ", param_2);

    param_2 = myQueuePop(obj);
    printf("%d ", param_2);
 
    int param_3 = myQueuePeek(obj);
    printf("%d ", param_3);
 
    bool param_4 = myQueueEmpty(obj);
 
    myQueueFree(obj);

}

MyQueue* myQueueCreate() {
    MyQueue *fila;
    fila = (MyQueue*)malloc(sizeof(MyQueue));
    fila->pilha1 = malloc(sizeof(Pilha));
    fila->pilha2 = malloc(sizeof(Pilha));
    *fila->pilha1 = NULL;
    *fila->pilha2 = NULL;
    return fila;
}

void myQueuePush(MyQueue* obj, int x) {
    Elem *p;
    while(*obj->pilha1 != NULL){
        p = *obj->pilha1;
        *obj->pilha1 = p->prox;
        p->prox = *obj->pilha2;
        *obj->pilha2 = p;
    }
    Elem *novo = (Elem *)malloc(sizeof(Elem));
    novo->x = x;
    novo->prox = *obj->pilha2;
    *obj->pilha2 = novo;
    while(*obj->pilha2 != NULL){
        p = *obj->pilha2;
        *obj->pilha2 = p->prox;
        p->prox = *obj->pilha1;
        *obj->pilha1 = p;
    }
}

int myQueuePop(MyQueue* obj) {
    Elem *p;
    p = *obj->pilha1;
    *obj->pilha1 = p->prox;
    int n;
    n = p->x;
    free(p);
    return n;
}

int myQueuePeek(MyQueue* obj) {
    Elem *p;
    p = *obj->pilha1;
    int n;
    n = p->x;
    return n;
}

bool myQueueEmpty(MyQueue* obj) {
    if(*obj->pilha1 == NULL){
        return true;
    }
    return false;
    
}

void myQueueFree(MyQueue* obj) {
    Elem *p;
    while(*obj->pilha1 != NULL){
        p = *obj->pilha1;
        *obj->pilha1 = p->prox;
        free(p);
    }
}
