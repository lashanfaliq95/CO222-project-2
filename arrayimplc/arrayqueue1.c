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

#define no_of_elements 5


struct stack{
int top;
int  maxsize;
int stack_array[no_of_elements];

};

struct queue{
int top;
int maxsize;
int queue_array[no_of_elements];

};

int main(){

int i,r;
	printf("Testing Queue\n");
	Queue* queue = CreateQueue();

	printf("Inserting values\n");
	for(i = 0; i < 6 ; i++)
	{	
	
		int result = QueueEnqueue(queue, i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in enqueuing queue\n");
		}
	}

	printf("Removing values\n");
	for(i = 0; i < 5 ; i++)
	{
		int result =QueueDequeue(queue, &r);
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in dequeuing queue\n");
		}
	}

	DeleteQueue(queue);

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
	
	for(i = 0; i < 5 ; i++){

		printf("%d ",stack->stack_array[i]);
	}
 DeleteStack(stack);	
 return 0;
}


Stack* CreateStack(){

Stack *stackptr=(Stack*)malloc(sizeof(Stack));//allocating memory for a stack
stackptr->top=-1;//making it a empty stack
stackptr->maxsize=no_of_elements;
return stackptr;
}

int DeleteStack(Stack* stack){
stack->top=-1;
free(stack);//free the memory allocated for the given stack

return 0;


}

int StackPush(Stack* stack, int value){

if(stack->top+1>=stack->maxsize){//overflow error
    
	return -1;
}
else {
    stack->top++;
    stack->stack_array[stack->top]=value;//pushing the values to the array
	return 0;}

}


int StackPop(Stack* stack, int* value){

if(stack->top==-1){//underflow error
  

	return -1;}
else{
  *value=stack->stack_array[stack->top];
  stack->stack_array[stack->top]='\0';//equalising the last element to NULL
  stack->top--;
	return 0;}


}


int StackPeek(const Stack* stack, int* value){
if(stack->top==-1){//underflow error
  return -1;}
else{*value=stack->stack_array[stack->top];
            
          return 0;}


}

Queue* CreateQueue(){

Queue *queueptr=(Queue*)malloc(sizeof(Queue));//allocating memory for a queue
queueptr->top=-1;//making it a empty emplty
queueptr->maxsize=no_of_elements;
return queueptr;

}

int DeleteQueue(Queue* queue){
if(sizeof(queue)==sizeof(Queue)){
free(queue);

return 0;}
else{return -1;}


}

int QueueEnqueue(Queue* queue, int value){
int i;
if((queue->top+1)>=(queue->maxsize)){//overflow error
    
	return -1;
}
else if(queue->top==-1) {
    queue->top++;
    queue->queue_array[queue->top]=value;//enqueue the first value to the array
	return 0;}
else{
for(i=queue->top;i>=0;i--){
queue->queue_array[i+1]=queue->queue_array[i];
}
 queue->queue_array[0]=value;
   queue->top++;
return 0;
}


}

int QueueDequeue(Queue* queue, int* value){
if(queue->top==-1){//underflow error
  

	return -1;}
else{
 *value=queue->queue_array[queue->top];
  queue->queue_array[queue->top]='\0';//equalising the last element to NULL
  queue->top--;
	return 0;}



}

int QueuePeek(const Queue* queue, int* value){
if(queue->top==-1){//underflow error
  return -1;}
else{*value=queue->queue_array[queue->top];
            
          return 0;}



}