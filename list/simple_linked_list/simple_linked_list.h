/**
 * \file simple_linked_list.h
 * \brief header for usual functions on a simply linked list (see sketch)
 * \date 15/08/2021
 * \author Aki Schmatzler
 */

#ifndef SIMPLE_LINKED_LIST
#define SIMPLE_LINKED_LIST

#include <assert.h> 
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


typedef struct strlist{
	dataType data;
	struct strlist *next;
}Strlist, *List;



//BASIC OPERATIONS AND OPERATIONS ON HEAD OF LIST

List newList();

List addHead(List l, dataType n);

List deleteHead(List l);

int isempty(List l);

dataType getHead(List l);

int belongs(List l, dataType n);	//checks if n belongs in the list 

unsigned int length(List l);

void show(List l);


//OPERATION ON FIRST OCCURENCE OF n

List delete_first(List l, dataType n); //deletes the first occurence of n in the list

List replace_first(List l, dataType n, dataType r); //replaces the first occurence of n by r

unsigned int research_first(List l, dataType n); //position of first occurence of n

List sublist_first(List l, dataType n); //returns the list starting at the first occurence of n


//OPERATION ON LAST ELEMENT

List beforeLast(List l); //returns list starting at element before the last one (intermediate function)

List deleteTail(List l); //deletes tail of the list

dataType getTail(List l); //returns tail of the list

List addTail(List l, dataType n);	//adds n at the end of the list


//OPERATION ON ELEMENT NUMBER I

dataType getNumberI(List l, unsigned int i); //returns the element number i

List add_n_at_i(List l, dataType n, unsigned int i); //adds element n at place i

List deleteNumberI(List l, unsigned int i);//deletes element number i
#endif