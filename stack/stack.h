#ifndef STACK
#define STACK

#include <stdio.h>
#include <stdlib.h>

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



typedef struct stack{
	dataType data;					//data in the stack
	struct stack *next;				//next item in the stack
} Stack_s, *Stack;


Stack newstack();					//creates a stack 

Stack push(Stack s, dataType data);

Stack pop(Stack s);

Stack replace(Stack s, dataType data);	//replaces the top of the stack

dataType top(Stack s);					//get top of stack

int isempty(Stack s);				

int height(Stack s);	

void destroyStack(Stack s);

#endif