#ifndef GENERIC_STACK
#define GENERIC_STACK

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
	void* data;
	struct stack *next;				//next item in the stack
} Stack_s, *Stack;


Stack newstack();					//creates a stack 

Stack push(Stack s, void* data);

Stack pop(Stack s);

Stack replace(Stack s, void* data);	//replaces the top of the stack

void* top(Stack s);					//get top of stack

int isempty(Stack s);				

int height(Stack s);				

#endif