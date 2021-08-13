#include "generic_stack.h"

Stack newstack() {
	return NULL;
}

Stack push(Stack s, void* data) {
	Stack newTop = (Stack) malloc(sizeof(Stack_s));
	if (newTop == NULL) abort();
	newTop->data = data;
	newTop->next = s;
	return newTop;
}

Stack pop(Stack s) {
	Stack newTop = s->next;
	free(s);
	return newTop;
}

Stack replace(Stack s, void* data) {
	s->data = data;
	return s;
}

void* top(Stack s) {
	return s->data;
}

int isempty(Stack s) {
	return s==NULL;
}

int height(Stack s) {
	if(s==NULL) return 0;
	else return 1 + height(p->next);
}