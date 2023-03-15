//
// Created by sagi yosef azulay on 22/02/2023.
//


#include<stdio.h>
#include<stdlib.h>

//3.1
typedef struct NODE_ {
 int data;
 struct NODE_ *next;
 struct NODE_ *prev;
} node, *pnode;

typedef struct QUEUE__ {
pnode head;
pnode tail;
} queue_, *pqueue_;

typedef struct QUEUE_ {
pqueue_ q;
} queue, *pqueue;


// 3.2

void push(queue q , int num) {
	pnode n = (pnode)malloc(sizeof(node));
	n->data = num;
	n->next = NULL;
	n->prev = q.q->tail;
	if (q.q->tail)
	    q.q->tail->next = n;
	if(!q.q->head)
		q.q->head=n;
	q.q->tail = n;
}

int pop(queue q){
	if ( !q.q->head) return -1;
	int rc = q.q->head->data;
	pnode h = q.q->head;
	q.q->head = q.q->head->next;
	free(h);
	return rc;
}

// 3.3

int main() {
queue q;
q.q = (pqueue_)malloc(sizeof(queue_));
q.q->head=NULL;
q.q->tail=NULL;
// this is since c99. its ok to initialize the longer way. .i.e q.tail = NULL ....
push(q,1);
push(q,2);
push(q,3);
pop(q);
printf("%d \n" , pop(q));
printf("%d \n" , pop(q)); // 2 , 3
free(q.q);
return 0;
}
