/**
 * \file avl_tree.h
 * \brief header for functions on avl trees
 * \date 16/08/2021
 * \author Aki Schmatzler
 */

#ifndef AVL_TREE
#define AVL_TREE

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * DATATYPE CAN BE CHANGED HERE TO FIT UR NEEDS
 * USE ONLY PRIMITIVE DATATYPES
 * FOR CUSTOM DATATYPES, SOME FUNCTIONS MAY NEED SOME CHANGE
 */
typedef int dataType;
/**
 * some examples that are valid in this implementation: 
 * typedef float dataType;
 * typedef size_t dataType;
 * typedef char dataType;
 */ 

typedef struct str_node {
	dataType data;
	unsigned int height;
	struct str_node *left, *right;
} node, *avl;

avl newAVL();

void updateh(avl a); //internal function to update height

avl implant(dataType x, avl g, avl d); //makes an avl out of 2 AVLs


avl left(avl a);	//returns left branch of avl

avl right(avl a);	//returns right branch of avl

bool isempty(avl a);

bool belongs(avl a, dataType x);

bool is_sorted(avl a);

void show(avl a);

unsigned int height(avl a);

avl	left_rotation(avl a);

avl	right_rotation(avl a);

avl	left_right_rotation(avl a);

avl right_left_rotation(avl a);

int unbalance_factor(avl a);	//checks how unbalanced the avl tree is

avl rebalance(avl a); //rebalances the avl using rotations

avl insert_avl(avl a, dataType x); //insert x in avl tree

avl deletion(avl a, dataType x);

avl otermax1(avl a); //internal function

dataType max(avl a);

dataType min(avl a);


#endif