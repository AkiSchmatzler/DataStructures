/**
 * \file double_linked_list.h
 * \brief header for usual functions on a double linked list (see sketch)
 * \date 15/08/2021
 * \author Aki Schmatzler
 */

#include <stdio.h>
#include <assert.h>

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

typedef struct strlist {
	dataType data;
	struct strlist *next;
	struct strlist *before;
} Strlist, *List;


List newList();

List addHead(List l, dataType d);

int isempty(List l);

dataType head(List l); //pre : l not empty!!!

int length(List l);

List deleteHead(List l);

dataType numberI(List l, int i); //returns element number i, pre: i<length(l)!!!

List deleteTail(List l);

List deleteTail_rec(List l, List sauv); //intermediate recursive function for deleteTail

List replace(List l, int i, dataType d); //replaces the data at position i on the list w data d

List replace_rec(List l, int i, dataType d, List sauv); //intermediate recursive function for replace

List insert(List l, int i, dataType x); //insert element x at position i of the list

List insert_rec(List l, int i, dataType x, List sauv); //intermediate recursive function for insertion at position i

List delete_i(List l, int i); //delete element at position i in the list

List delete_i_rec(List l, int i, List sauv); //intermediate recursive function for delete_i