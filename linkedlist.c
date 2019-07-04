// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
	char data; // each listNode containes a charachter
	struct listNode *nextPtr; // pointer to next node
} ListNode;

typedef ListNode *ListNodePtr; // synonym for ListNode*

// Prototypes
void insert(ListNodePtr *sPtr,char value);
void instructions(void);

int main(void){
	ListNodePtr startPtr = NULL; // initialy there are no nodes
	char item;
	instructions(); // display menu
	printf("%s","? ");

	unsigned int choice; // user's choice
	scanf("%u",&choice);
	printf("%u",choice);
	return 0;
}

void instructions(void){
	puts("Enter your choice:\n"
		"1 to insert an element into the list.\n"
		"2 to delete an element from the list.\n"
	);
}

void insert(ListNodePtr *sPtr, char value){
	ListNodePtr newPtr = malloc(sizeof(ListNode)); // create Node

	if(newPtr != NULL){ // is space available ?
		newPtr->data = value; // place value in node
		newPtr->nextPtr = NULL;// node does not link to another node

		ListNodePtr previousPtr = NULL;
		ListNodePtr currentPtr = *sPtr;

		// loop to find the correct location in the list
		while(currentPtr != NULL && value > currentPtr->data){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		// insert node at begining of the list
		if(previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}else{ // insert new node between previousPtr and currentPtr
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}else{
		printf("%c not inserted. No memory available.\n",value);
	}
}