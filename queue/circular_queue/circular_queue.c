/**
 * \file circular_queue.c
 * \brief definition of circular queue usual functions
 * \date 14/08/2021
 * \author Aki Schmatzler
 */

#include "circular_queue.h"

Queue newQueue(){
	return NULL;
}

Queue addHead(Queue q, dataType data){
	Queue q1 = (Queue) malloc(sizeof(strQueue));
	if (q1 == NULL) abort(); //malloc error
	q1->data = data;
	if(isempty(q)) q1->next = q1; //because it's circular
	else {
		q1->next = q->next;
		q->next = q1;
	}
	return q1;
}

Queue deleteHead(Queue q){
	if (q == NULL){
		fprintf(stderr, "Queue needs a head to be decapitated..\n");
		return NULL;
	}

	Queue res;
	Queue q2;

	if(q == q->next) { //if there's only one element
		free(q);
		res=NULL;
	}
	else{
		q2 = q->next;
		q->next = q->next->next;
		free(q2);
		res = q;
	}
	return res;
}

dataType head(Queue q){
	return q->next->data;
}

int isempty(Queue q){
	return q == NULL;
}

unsigned int length(Queue q){
	return isempty(q) ? 0 : lengthIntermediate(q->next,q);
}

unsigned int lengthIntermediate(strQueue* q1, strQueue *q2){
	return q1 == q2 ? 1 : 1 + lengthIntermediate(q1->next,q2);
}
