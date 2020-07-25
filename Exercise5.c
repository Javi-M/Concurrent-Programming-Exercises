/*
 ============================================================================
 Name        : Exercise5.c
 Author      : Javier Márquez
 Version     : 1

 Description : Exercise 5 from topic 2's exercises sheet. 
 Insert 100 random elements into a linked list of integers.
 Then, sort the list using bubble sort algorithm.
 I think it works!
 (This is coded specifically for a size of 100).
 (It is not difficult to use it with different sizes, just change loop conditions).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Create linked list
typedef struct NodeNum *ListNum;
struct NodeNum{
	int num;
	ListNum next;
};

//Bubble sort algorithm

void bubbleSort(ListNum list);
void printList(ListNum list);
void checkOrder(ListNum list);

int main(){
	ListNum list = malloc(sizeof(struct NodeNum));
	//No malloc => Segmentation fault error
	list -> num = rand();
	//printf("%i\n", list -> num);

	ListNum aux = list;

	for(int i = 0; i < 99; ++i){ //One element is already put in list
		aux -> next = malloc(sizeof(struct NodeNum));
		//aux -> next = malloc ... must be done BEFORE aux = aux -> next!!!
		aux = aux -> next;
		aux -> num = rand();
		aux -> next = NULL;
	}

	//Until here code works and we have random elements list!

	bubbleSort(list);

	printList(list);

	checkOrder(list);

}

void bubbleSort(ListNum list){
	ListNum left, right;
	bool ordered = false;

	while (!ordered){
		left = list;
		right = list -> next;
		ordered = true;

		//Go through all the list
		//Swap each time needed
		while(right != NULL){
			if(right->num < left->num){
				int aux = right -> num;
				right -> num = left -> num;
				left -> num = aux;
				ordered = false;
				//If no swap done, ordered keeps true!
			}
	
			left = left -> next;
			right = right -> next;
		}
	}
}

void printList(ListNum list){
	ListNum aux = list;
	for (int i = 0; i < 100; ++i) {
		printf("%i; \n", aux -> num);
		aux = aux -> next;
	}
}

void checkOrder(ListNum list){
	bool ordered = true;
	ListNum left, right;
	
	int i = 0;
	left = list;
	right = list -> next;

	while (ordered && i < 99){
		if(left->num > right->num) 
			ordered = false;
		left = left -> next;
		right = right -> next;
		++i;
	}

	if(ordered)
		printf("The list is ordered!\n");
	else
		printf("The list is not completely ordered!\n");
}
