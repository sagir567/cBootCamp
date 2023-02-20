#include <stdio.h>
#include <stdlib.h>
#include "myStack.h"



typedef struct Node{
    int data;
    struct Node* next;
} Node , pNode;


static Node * top = NULL;

void push(int data){
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error: memory allocation failed\n");
        exit(0);
    }
    newNode->data =data;
    newNode-> next = top;
    top=newNode;
}
int pop(){
    pNode* temp= top;
    if(!isEmpty()){
        int data = temp->data;
        top = temp->next;
        free(temp);
        return data;
    }
    printf("ERROR: stack is empty\n");
    return -1;
}

int isEmpty(){
    return(top ==NULL?1:0);
}
int peek(){
    if(!isEmpty()){
         int data = top->data;
         return data;
    }
    printf("ERROR: stack is empty\n");
    return -1;
}
void toString(){
    if(!isEmpty()){
        Node* temp = top;
        while((temp->next) != NULL){
            printf("|%.2d|\n",temp->data);
            temp=temp->next;
        }
        printf("|%d|\n",temp->data);
        printf("---");
    }
}


int main(){
    push(10);
    push(3);
    push(27);
    push(1);
    push(22);
    push(9);
    toString();

    return -1;
}

