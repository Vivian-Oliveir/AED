//You are given two non-empty linked lists representing two non-negative integers. 
//The digits are stored in reverse order, and each of their nodes contains a single digit. 
//Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

int menu(void);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
struct ListNode * list(struct ListNode *first_node);
struct ListNode * enter_list(struct ListNode *head);

int main(){
    struct ListNode *l1_num1, *l2_num1;
    l1_num1 = list(l1_num1);
    l2_num1 = list(l2_num1);

    int op;
    while(1){
        op = menu();
        switch(op){
            case 1:
                enter_list(l1_num1);
                break;
            case 2:
                enter_list(l2_num1);
                break;
            case 3:
                addTwoNumbers(l1_num1, l2_num1);
                break;
            case 4:
                exit(1);
        }
    }
}

int menu(void){
    int op=0;
    printf("1. Enter number to list 1\n");
    printf("2. Enter number to list 2\n");
    printf("3. Add the two numbers\n");
    printf("4. Exit\n");
    printf("Enter an option: ");
    scanf("%d",&op);
    printf("_____________________________________\n");
    return op;
}

struct ListNode * list(struct ListNode *first_node){
    first_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    first_node->next = NULL;
    return first_node;
}

struct ListNode * enter_list(struct ListNode *head){
    struct ListNode *p;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    printf("Enter a number: ");
    scanf("%d",&p->val);
    p->next = head->next;
    head->next = p;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int l1_size=0, l2_size=0;
    struct ListNode *p;
    for(p=l1->next; p!=NULL; p=p->next){
        l1_size++;
    }
    printf("%d\n", l1_size);
}

