/**
 * \file avl_tree.c
 * \brief definition functions on avl trees
 * \date 16/08/2021
 * \author Aki Schmatzler
 */



#include "avl_tree.h"

/////////////////////////////
avl newAVL() { 
	return NULL;
}

 void updateh(avl a) {
	if (a->left == NULL && a->right == NULL) a->height = 0;
	else if (a->left == NULL) a->height = 1 + a->right->height;
	else if (a->right == NULL) a->height = 1 + a->left->height;
	else a->height = 1 + (a->left->height > a->right->height ? a->left->height : a->right->height);
}

avl implant(dataType x, avl l, avl r) {
	avl n = (avl) malloc(sizeof(node));
	n->data = x;
	n->left = l;
	n->right = r;
	updateh(n);
	return n;
}

avl ag(avl a) {
	if (a != NULL) return a->left;
	return NULL;
}

avl ad(avl a) {
	if (a != NULL) return a->right;
	return NULL;
}

bool isempty(avl a) {
	return a == NULL;
}

bool belongs(avl a, dataType x) {
	if (a == NULL) return false;
	if (a->data == x) return true;
	else if (x<a->data) return belongs(a->left, x);
	else return belongs(a->right, x);
}

bool is_sorted(avl a) {
	bool isSorted = true;
	if (a == NULL) return true;
	if (a->left != NULL) isSorted = (a->data > max(a->left)) && is_sorted(a->left);
	if (a->right != NULL) isSorted = (a->data < min(a->right)) && is_sorted(a->right);
	return isSorted;
}

unsigned int height(avl a) {
	return a->height;
}

void show(avl a) {
	if (a == NULL) return;
	show(a->left);
	printf("%d(%u) ", a->data, a->height);
	show(a->right);
}

// rotations
avl right_rotation(avl a) {
	avl temp;

	if (a == NULL) abort(); // erreur
	if (a->left == NULL) abort(); // erreur
	temp = a->left;
	a->left = temp->right;
	updateh(a);
	temp->right = a;
	updateh(temp);
	return temp;
}

avl	left_rotation(avl a) {
	avl temp;

	if (a == NULL) abort(); // erreur
	if (a->right == NULL) abort(); // erreur
	temp = a->right;
	a->right = temp->left;
	updateh(a);
	temp->left = a;
	updateh(temp);
	return temp;
}

avl	left_right_rotation(avl a) {
	a->left = left_rotation(a->left);
	updateh(a);
	return right_rotation(a);
}

avl right_left_rotation(avl a) {
	a->right = right_rotation(a->right);
	updateh(a);
	return left_rotation(a);
}

int unbalance_factor(avl a) { 
	int hg = a->left == NULL ? -1 : (int)a->left->height;
	int hd = a->right == NULL ? -1 : (int)a->right->height;
	return hg-hd;  
}

avl rebalance(avl a) {
 	int de = unbalance_factor(a);
 	if (de == 0 || de == -1 || de == 1) return a;
 	if (de == +2 && unbalance_factor(a->left) > 0) return right_rotation(a);
 	if (de == -2 && unbalance_factor(a->right) < 0) return left_rotation(a);
 	if (de == +2 && unbalance_factor(a->left) <= 0) return left_right_rotation(a);
 	if (de == -2 && unbalance_factor(a->right) >= 0) return right_left_rotation(a);
 	return a;
}
  

avl insert_avl(avl a, dataType x) {
	if (a == NULL) return implant(x, newAVL(), newAVL());
	if (x <= a->data)  a->left = insert_avl(a->left, x);
	else a->right = insert_avl(a->right, x);
	updateh(a);
	return rebalance(a);
}

avl otermax1(avl a) {
	if (a->right == NULL) return a->left;
	a->right = otermax1(a->right);
	updateh(a);
	return rebalance(a);
}

dataType max(avl a) {
	if (a->right == NULL) return a->data;
	return max(a->right);
}

dataType min(avl a) {
	if (a->left == NULL) return a->data;
	return min(a->left);
}

avl deletion(avl a, dataType x) {
	avl tmp = NULL;
	if (a == NULL) return NULL;
	if (a->data == x)
	{
		avl tmp = a;
		if (a->right == NULL) return a->left;
		if (a->left == NULL) return a->right;
		a->data = max(a->left);
		a->left = otermax1(a->left);
		updateh(a);
		free(tmp);
		return rebalance(a);
	}
	if (x<a->data) a->left = deletion(a->left, x);
	else a->right = deletion(a->right, x);
	updateh(a);
	return rebalance(a);
}