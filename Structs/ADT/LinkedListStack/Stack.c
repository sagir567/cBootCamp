#include <stdio.h>
#include <stdlib.h>




typedef struct Node{
    int data;
    struct Node* next;

} Node , *pNode;



typedef struct Stack__{
    Node* top;
    int size;
} Stack_, *pStack_;

typedef struct Stack_{
    pStack_ s;
} Stack , *pStack;

void push(Stack s, int data){
    pNode node = (pNode)malloc(sizeof(Node));
    node->data = data;
    if(s.s->top){
        node->next=s.s->top;
        s.s->top=node;
    }
    else{
        s.s->top=node;
    }
}
int pop(Stack s){
    if(!s.s->top){
        printf("ERROR: stack is empty!");
    }
    int data =s.s->top->data;
    pNode t = s.s->top;
    s.s->top=t->next;
    free(t);
    printf("%d has popped!\n",data);
    return data;
}

void printS(Stack s){

    pNode n = s.s->top;
    printf("%d ",n->data);

    while(n=n->next){
        printf("----> %d",n->data);
    }
    printf("\n");
}




int main(){
    Stack s;
    s.s=(pStack_) malloc(sizeof(pStack_));
    s.s->top =NULL;
    s.s->size=0;

    push(s,1);
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    printS(s);

    pop(s);
    pop(s);
    printS(s);


    return -1;
}

