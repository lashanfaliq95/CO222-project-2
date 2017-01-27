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


struct stack{
int top;
int  maxsize;
int stack_array[no_of_elements];

};

struct queue{

int queue_array[no_of_elements];

};

int main(){

int i;
	int r;
	int result; 

	
	printf("\nTesting Stack\n");

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
			printf("Error in pushing to stack");
		}
	}

	for(i = 0; i < 5 ; i++){
		printf("before popping %d\n",stack->stack_array[i]);
	}
	for(i = 0; i < 5 ; i++)
	{
		int result = StackPeek(stack, &r);
		if(result == 0)
		{
			printf("peeking %d\n",r);
		}
		else
		{
			printf("Error in peeking values \n");
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
			printf("Error in popping values");
		}
	}
	 result = StackPeek(stack, &r);
		if(result == 0)
		{
			printf("peeking %d\n",r);
		}
		else
		{
			printf("Error in peeking values \n");
		}
	for(i = 0; i < 5 ; i++){
		printf("after popping  %d\n",stack->stack_array[i]);
	}
	
	DeleteStack(stack); 



return 0;
}


stack* CreateStack(){

Stack *stackptr=(stack*)malloc(sizeof(stack));
stackptr->top=-1;
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
    stack->top++;
    stack->stack_array[stack->top]=value;
	return 0;}

}


int StackPop(Stack* stack, int* value){

if(stack->stack_array[stack->top]==-1){//underflow error
  

	return -1;}
else{
  *value=stack->stack_array[stack->top];
  stack->stack_array[stack->top]='\0';
  stack->top--;
	return 0;}


}


int StackPeek(const Stack* stack, int* value){
if(stack->top==-1){//underflow error
  return -1;}
else{*value=stack->stack_array[stack->top];
            
          return 0;}


}