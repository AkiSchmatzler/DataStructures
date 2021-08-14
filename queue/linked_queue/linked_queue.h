/**
 * \file linked_queue.h
 * \brief header for linked queue
 * \date 14/08/2021
 * \author Aki Schmatzler
 */



#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include <stdio.h>

/**
 * DATATYPE CAN BE CHANGED HERE TO FIT UR NEEDS
 * USE ONLY PRIMITIVE DATATYPES
 * FOR CUSTOM DATATYPES, SOME FUNCTIONS MAY NEED SOME CHANGE
 */
typedef int dataType;
/**
 * some examples that are valid : 
 * typedef float dataType;
 * typedef size_t dataType;
 * typedef char dataType;
 */ 

typedef struct strqueue{
	dataType data;
	struct strqueue *next;
} Strqueue;

typedef struct squeue{
	Strqueue *head; 
	Strqueue *tail;
} Queue;

Queue newQueue();

Queue addTail(Queue q, dataType data);

Queue deleteHead(Queue q);

dataType head(Queue q);//pre = q not empty

int isempty(Queue q);

unsigned int length(Queue q);

unsigned int lengthIntermediate(Strqueue* q1, Strqueue *q2);

#endif