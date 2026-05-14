//Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack 
//should support all the functions of a normal stack (push, top, pop, and empty).
//Implement the MyStack class:
//void push(int x) Pushes element x to the top of the stack.
//int pop() Removes the element on the top of the stack and returns it.
//int top() Returns the element on the top of the stack.
//boolean empty() Returns true if the stack is empty, false otherwise.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemento{
    int num;
    struct elemento *prox;
};

struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

typedef struct fila Fila;
typedef struct elemento Elemento;

typedef struct {
    Fila *fila1;
    Fila *fila2;
} MyStack;

MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);
void myStackFree(MyStack* obj);

int main(){
    int x = 4;
    MyStack* obj = myStackCreate();

    myStackPush(obj, x);
    myStackPush(obj, 5);
 
    int param_2 = myStackPop(obj);
    printf("%d ", param_2);
 
    int param_3 = myStackTop(obj);
    printf("%d ", param_3);
 
    bool param_4 = myStackEmpty(obj);
    printf("%d ", param_4);
 
    myStackFree(obj);
}

MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->fila1 = (Fila*)malloc(sizeof(Fila));
    stack->fila1->final = NULL;
    stack->fila1->inicio = NULL;
    stack->fila1->qtd = 0;
    stack->fila2 = (Fila*)malloc(sizeof(Fila));
    stack->fila2->final = NULL;
    stack->fila2->inicio = NULL;
    stack->fila2->qtd = 0;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    novo->num = x;
    novo->prox = NULL;
    if(obj->fila1->inicio == NULL){
        obj->fila1->inicio = novo;
    } else {
        obj->fila1->final->prox = novo;
    }
    obj->fila1->final = novo;
    obj->fila1->qtd++;

    Elemento *passar;
    while(obj->fila2->inicio != NULL){
        passar = obj->fila2->inicio;
        obj->fila2->inicio = obj->fila2->inicio->prox;
        obj->fila2->qtd--;
        passar->prox = NULL;
        obj->fila1->final->prox = passar;
        obj->fila1->final = passar;
        obj->fila1->qtd++;
    }

    passar = obj->fila1->inicio;
    obj->fila1->inicio = obj->fila1->inicio->prox;
    passar->prox = NULL;
    obj->fila2->inicio = passar;
    obj->fila2->final = passar;
    obj->fila2->qtd++;
    obj->fila1->qtd--;

    while(obj->fila1->inicio != NULL){
        passar = obj->fila1->inicio;
        obj->fila1->inicio = obj->fila1->inicio->prox;
        passar->prox = NULL;
        obj->fila1->qtd--;
        obj->fila2->final->prox = passar;
        obj->fila2->final = passar;
        obj->fila2->qtd++;
    }
    
}

int myStackPop(MyStack* obj) {
    Elemento *retorno;
    retorno = obj->fila2->inicio;
    obj->fila2->inicio = obj->fila2->inicio->prox;
    int n;
    n = retorno->num;
    free(retorno);
    return n;
}

int myStackTop(MyStack* obj) {
    Elemento *retorno;
    retorno = obj->fila2->inicio;
    return retorno->num;    
}

bool myStackEmpty(MyStack* obj) {
    if(obj->fila2->inicio == NULL){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    Elemento *passar;
    while(obj->fila2->inicio != NULL){
        passar = obj->fila2->inicio;
        obj->fila2->inicio = obj->fila2->inicio->prox;
        obj->fila2->qtd--;
        free(passar);
    }
    free(obj->fila1);
    free(obj->fila2);
}
