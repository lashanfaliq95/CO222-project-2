#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include "StackAndQueue.h"

#define NO_OF_ELEMENTS 5

typedef struct stack Stack;
typedef struct queue Queue;

Stack* CreateStack();
int DeleteStack(Stack* stack);

Queue* CreateQueue();
int DeleteQueue(Queue* queue);

int StackPush(Stack* stack, int value);
int StackPop(Stack* stack, int* value);
int StackPeek(const Stack* stack, int* value);

int QueueEnqueue(Queue* queue, int value);
int QueueDequeue(Queue* queue, int* value);
int QueuePeek(const Queue* queue, int* value);

struct stack* numbers; // to store the address of the first node


struct stack{//here a maxsize is not neccassary because  overflow is not possible in this implementation (unless memory is exhausted)
int top;
int value;
struct stack* next;

}*topptr;//defining a pointer variable to store the top node

struct queue{
int top;
int value;
struct  queue * next;
};

 
Stack*current;

int main(){
int i,r;

	printf("\nTesting Stack\n");

	Stack* stack = CreateStack();
	for(i = 1; i < 6; i++)
	{
		int result = StackPush(stack, i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in pushing to stack");
		}
	}
	
	for(i = 1; i < 8 ; i++)
	{
		int result = StackPop(stack, &r);
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in popping values");
		}
	}

     DeleteStack(stack);

return 0;
}



Stack* CreateStack(){

Stack* stack=(Stack*)malloc(sizeof(Stack));
topptr=stack;//equalising the top node 
stack->top=-1;//making it a empty stack
stack->next=NULL;

return stack;
}

int StackPush(Stack* stack, int value){
           Stack * current;//a temperory variable
           stack=topptr;//assigning the current top to the stack
           stack->value=value;
           stack->top++;
           current=(Stack *)malloc(sizeof(Stack));//making a new node
           current->next=topptr;
           topptr=current;//assigining the new top node
           
           
 return 0;
}

int StackPop(Stack* stack, int* value){
stack=topptr;//because we malloc one extra node in push
if(stack->top==0){//underflow error
  

	return -1;}
else{
  *value=stack->value;
  stack->value='\0';//equalising the last element to NULL

  topptr=topptr->next;

	return 0;}

}

int DeleteStack(Stack* stack){
 Stack * current;//a temperory variable
 for(current=topptr->next;current!=NULL;current=current->next){

 	free(current);
 }

return 0;
}