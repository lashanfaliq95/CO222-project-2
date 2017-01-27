#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//#include "StackAndQueue.h"

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

#define no_of_elements 10


typedef struct stack{
int top;
int  maxsize;
int stack_array[no_of_elements];

}stack;

int main(){
/*int i,r;
Stack* stack = CreateStack();
	for(i = 0; i < 5 ; i++)
	{
		int result = StackPush(stack, i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in pushing to stack \n");
		}
	}
for(i = 0; i < 5 ; i++)
	{
		int result = StackPop(stack, &i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in popping values \n");
		}
	}
	
	DeleteStack(stack);*/



	int i;
	int r;
	int result; 
printf("\nTesting Stack\n");

	Stack* stack = CreateStack();
	for(i = 0; i < 5 ; i++)
	{		r = rand();
		int result = StackPush(stack, r);
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in pushing to stack \n");
		}	
	}

	for(i = 0; i < 5 ; i++)
	{
		int result = StackPop(stack, &r);
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in popping values \n");
		}
	}
	
	for(i = 0; i < 5 ; i++){

		printf("%d \n",stack->stack_array[i]);
	}
	DeleteStack(stack); 

return 0;
}


stack* CreateStack(){

stack *stackptr=(stack*)malloc(sizeof(stack));
stackptr->top=0;
stackptr->maxsize=no_of_elements;
return stackptr;
}

int DeleteStack(Stack* stack){

free(stack);


}

int StackPush(Stack* stack, int value){

if(stack->top==stack->maxsize){
    
	return -1;
}
else {
    stack->stack_array[stack->top]=value;
	stack->top++;
	return 0;}

}


int StackPop(Stack* stack, int* value){

if(*value==stack->stack_array[stack->top-1]){//substract one because after value is addes to array top is incrmented by one even if no element is added afterwords.
  
 stack->stack_array[stack->top-1]='\0';
stack->top=stack->top-2;
	return 0;}
else{return -1;}


}