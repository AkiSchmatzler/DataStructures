/**
 * \file stack.c
 * \brief definition of usual functions on a stack
 * \date 14/08/2021
 * \author Aki Schmatzler
 */

#include "stack.h"

Stack newstack() {
	return NULL;
}

Stack push(Stack s, dataType data) {
	Stack newTop = (Stack) malloc(sizeof(Stack_s));
	if (newTop == NULL) abort();
	newTop->data = data;
	newTop->next = s;
	return newTop;
}

Stack pop(Stack s) {
	if (s == NULL) return NULL;
	else {
		Stack newTop = s->next;
		free(s);
		return newTop;
	}
}

Stack replace(Stack s, dataType data) {
	s->data = data;
	return s;
}

dataType top(Stack s) {
	return s->data;
}

int isempty(Stack s) {
	return s == NULL;
}

int height(Stack s) {
	if(s == NULL) return 0;
	else return 1 + height(s->next);
}

void destroyStack(Stack s) {
	if (s == NULL) return;
	else {
		destroyStack(s->next);
		free(s);
	}
}