/**
 * \file simple_linked_list.c
 * \brief definition of usual functions on a simply linked list (see sketch)
 * \date 15/08/2021
 * \author Aki Schmatzler
 */

#include "simple_linked_list.h"

List newList() {
	return NULL;
}

List addHead(List l, dataType n) {
	List l1 = (List) malloc(sizeof(Strlist));
	assert(l1 != NULL);
	l1->data = n;
	l1->next = l;
	return l1;
}

List deleteHead(List l) {
	if(isempty(l)) return l;
	List l1 = l->next;
	free(l);
	return l1;
}

int isempty(List l) {
	return l == NULL;
}

dataType getHead(List l) {
	return l->data;
}

int belongs(List l, dataType n) {
	for(int i = 0; i<length(l); i++) {
		if(l->data==n) return 1; 
		else l = l->next;
	}
	return 0;
}

unsigned int length(List l) {
	if(isempty(l)) return 0;
	else return 1+length(l->next);
}


void show(List l) {
	while(!isempty(l)) {
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}


List delete_first(List l, dataType n) {
	List l1 = l;
	for(int i = 0; i<length(l); i++) {

		if(l1->data == n) {
			l1 = deleteHead(l1);
			free(l1);
			return l;
		}
		else l1 = l1->next;
	}
	return NULL;
}


List replace_first(List l, dataType n, dataType r) {

	List l1 = l;
	for(int i = 0; i<length(l); i++) {

		if(l1->data == n) {
			l1->data = r;
			return l;
		}
		else l1 = l1->next;
	}
	return NULL;
}

unsigned int research_first(List l, dataType n){
	if(l->data == n) {
		return 1;
	}
	else return 1 + research_first(l->next, n);
}

List sublist_first(List l, dataType n) {	
	if(l->data == n) {
		return l;
	}
	else {
		List l2 = l->next;
		free(l);
		return sublist_first(l2, n);
	}
}


List beforeLast(List l) {
	if(length(l) == 1 || length(l) == 0) return l;
	else if(l->next->next == NULL) return l;
	else return beforeLast(l->next);
}



List deleteTail(List l) {
	List l1 = beforeLast(l);
	List l2 = l;

	while(l2->next!=l1->next) {
		l2=l2->next;
	}
	free(l2->next);
	l2->next = NULL;
	return l;
}

dataType getTail(List l){
	return (length(l) == 1)? l->data : getTail(l->next);
}

List addTail(List l, dataType n) {
	List l1 = l;
	while(l1->next != NULL) l1 = l1->next;
	List l2 = (List) malloc(sizeof(Strlist));
	assert(l2 != NULL);
	l2->next = NULL;
	l1->next = l2;
	l2->data = n;
	return l;
}


dataType getNumberI(List l, unsigned int i) {
	List l1 = l;
	int j = 0;
	while( j<i) {
		l1 = l1->next;
		j++;
	}
	return l1->data;
}

List add_n_at_i(List l, dataType n, unsigned int i){

	List l1 = (List) malloc(sizeof(Strlist));
	assert(l1 != NULL);
	l1->data = n;
	List l2 = l;
	int j = 1;

	while(j<i){
		l2 = l2->next;
		j++;
	}

	List l3 = l2->next;
	l2->next = l1;
	l1->next = l3;
	return l;
}

List deleteNumberI(List l, unsigned int i){
	List l1 = l;
	int j = 1;

	while( j<i){
		l1 = l1->next;
		j++;
	}
	List l2 = l1->next;
	l1->next = l1->next->next;
	free(l2);
	return l;
}

