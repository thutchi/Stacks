// Stack Implementation.cpp : Defines the entry point for the console application.
//
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include<crtdbg.h> //used for memory leak detection
typedef struct node //define a structure (Stack)
{
	int info;
	struct node * ptr;
}node;

void push(int, node ** top_node);
void pop(node ** top_node);
void destroy(node ** top_node);
void display(node * top_node);

int main(int argc, char ** argv)
{
	node * top_node = NULL; //creates the top node...
	push(1, &top_node);
	push(5, &top_node);
	push(55, &top_node);
	display(top_node);
	pop(&top_node);
	display(top_node);
	pop(&top_node);
	display(top_node);
	pop(&top_node);
	display(top_node);
	push(1, &top_node);
	display(top_node);
	destroy(&top_node);
	_CrtDumpMemoryLeaks();
    return 0;
}

void display(node * top_node)
{
	node * temp = top_node; //saves a temporary stack of the top_node. 
	if (top_node == NULL)
	{
		printf("The Stack is empty\n");
		return;
	}
	while (temp != NULL)
	{
		printf("%d \n", temp->info);
		temp = temp->ptr;
	}
}

void push(int data, node ** top_node)
{
	if (*top_node == NULL)
	{
		(*top_node) = (struct node *) malloc(sizeof(struct node)); //allocated memory for a node
		(*top_node)->ptr = NULL; //points to NULL because it is the first item in the stack
		(*top_node)->info = data; //adds the data to top_node -> info
	}

	else
	{
		node * temp = (struct node *) malloc(sizeof(struct node)); //allocated memory for a node
		temp->ptr = *top_node; //points the temporary node to the top_node that holds all other information in the stack
		temp->info = data; 
		*top_node = temp; //sets the top_node equal to the temp node, resulting in top_node containing all the information in the stack
	}
}

void pop(node ** top_node)
{
	node * temp_node = *top_node; 
	if (temp_node == NULL) //checks that the top node is not null
	{
		printf("\n ERROR, The stack is currently empty\n");
		return;
	}
	else
	{
		temp_node = temp_node->ptr; //moves the top of the stack one item down
		printf("popped value = %d\n", (*top_node)->info); //prints the top value in the orginal stack
		free(*top_node); //frees the top node
		*top_node = temp_node; //the top node is now equal to the next item in the stack 
	}
}
//frees all the nodes in the stack 
void destroy(node ** top_node) 
{
	node * temp = *top_node; 
	while (temp != NULL)
	{
		temp = temp->ptr;
		free(*top_node);
		*top_node = temp;
	}
	free(temp);
	
}

