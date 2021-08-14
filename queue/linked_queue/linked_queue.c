/**
 * \file linked_queue.c
 * \brief definition of linked queue usual functions
 * \date 14/08/2021
 * \author Aki Schmatzler
 */

#include "linked_queue.h"

Queue newQueue(){
	Queue q;
	q.head = NULL;
	q.tail = NULL;
	return q;
}

Queue addTail(Queue q, dataType data){
	Strqueue *q1 = (Strqueue*) malloc(sizeof(Strqueue));
	q1->data = data;
	q1->next = NULL;
	if(q.head == NULL) {
		q.head = q1;
		q.tail = q1;
	}
	else{
		q.tail->next = q1;
		q.tail = q1;}
	return q;
}

Queue deleteHead(Queue q){
	Strqueue * q1 = q.head;
	if(q.head == q.tail) {
		q.head = NULL;
		q.tail = NULL;
	}
	else q.head = q.head->next;
	free(q1);
	return q;
}

dataType head(Queue q){//pre = q not empty
	return q.head->data;
}

int isempty(Queue q){
	return q.head == NULL;
}

unsigned int length(Queue q){
	return isempty(q) ? 0 : lengthIntermediate(q.head, q.tail);
}

unsigned int lengthIntermediate(Strqueue* q1, Strqueue *q2){
	return (q1 == q2) ? 1 : 1+lengthIntermediate(q1->next, q2);
}

