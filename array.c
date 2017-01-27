#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "StackAndQueue.h"


#define NO_OF_ELEMENTS 100000
struct stack{//creating the stack
int top;
int  maxsize;
int stack_array[NO_OF_ELEMENTS ];

};

struct queue{//creating the queue
int top;
int maxsize;
int queue_array[NO_OF_ELEMENTS ];

};


Stack* CreateStack(){

Stack *stackptr=(Stack*)malloc(sizeof(Stack));//allocating memory for a stack
stackptr->top=-1;//making it a empty stack
stackptr->maxsize=NO_OF_ELEMENTS ;
return stackptr;
}

int DeleteStack(Stack* stack){

free(stack);
return 0;


}

int StackPush(Stack* stack, int value){

if((stack->top+1)>=(stack->maxsize)){//overflow error
    
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
queueptr->maxsize=NO_OF_ELEMENTS ;
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