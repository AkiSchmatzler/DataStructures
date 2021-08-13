#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

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


typedef struct strQueue{
	dataType data;
	struct strQueue *next; //--> pointer to the next element (see sketch)
} strQueue, *Queue;


Queue newQueue();

Queue addTail(Queue q, dataType data);

Queue deleteHead(Queue q);

dataType head(Queue q);

int isempty(Queue q);

dataType length(Queue q);

dataType lengthIntermediate(strQueue* q1, strQueue *q2);

#endif