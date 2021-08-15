/**
 * \file double_linked_list.c
 * \brief definition usual functions on a double linked list (see sketch)
 * \date 15/08/2021
 * \author Aki Schmatzler
 */

#include "double_linked_list.h"


List newList() {
	return NULL;
}

List addHead(List l, dataType d) {
	List l1 = (List) malloc(sizeof(Strlist));
	assert(l1!=NULL);
	l1->data = d;
	l1->next = l;
	l1->before = NULL;
	if(l!=NULL) l->before = l1;
	return l1;
}

int isempty(List l) {
	return l==NULL;
}

dataType head(List l) {//pré : l not empty!
	return l->data;
}


int length(List l) {
	return isempty(l)? 0 : 1 + length(l->next);
}

List deleteHead(List l) {
	if(isempty(l)) return l;
	List l1 = l->next;
	free(l);
	l1->before = NULL;
	return l1;
}


dataType numberI(List l, int i) {
	if(i == 0) return l->data;
	else return numberI(l->next, i-1);
}

List deleteTail(List l) {
	return deleteTail_rec(l,l);
}

List deleteTail_rec(List l, List sauv) {
	if(l == NULL) return NULL;
	else if(l->next == NULL) {
		if(l->before == NULL) sauv = NULL;
		else l->before->next = NULL;
		free(l);
		return sauv;
	}
	else return deleteTail_rec(l->next, sauv);
}


List replace(List l, int i, dataType d) {
	return replace_rec(l, i, d, l);
}

List replace_rec(List l, int i, dataType d, List sauv) {
	if(l==NULL) return l;
	else if(i==0){
		l->data = d;
		return sauv;
	}
	else return replace_rec(l->next, i-1, d, sauv);
}

List insert(List l, int i, dataType x) {
	return insert_rec(l,i,x,l);
}

List insert_rec(List l, int i, dataType x, List sauv) {
	List prec;
	if(l==NULL) return sauv;
	else if(i==0) {
		prec = l->before;
		if(prec != NULL){
			l->before->next = addHead(l,x);
			l->before->before = prec;
			return sauv;
		}
		else return addHead(l,x);
	}
	else return insert_rec(l->next, i-1, x, sauv);
}



List delete_i(List l, int i) {
	return delete_i_rec(l,i,l);
}

List delete_i_rec(List l, int i, List sauv) {
	List prec;
	if(l==NULL) return sauv;
	else if(i==0){
		prec = l->before;
		l=deleteHead(l);
		if(prec==NULL) sauv=l;
		else{
			l->before = prec;
			prec->next = l;
		}
		return sauv;
	}
	else return delete_i_rec(l->next, i-1, sauv);
}
