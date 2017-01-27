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

}*topptr;//defining a pointer variable to store address of the top node

struct queue{
int top;
int value;
struct  queue * next;
}*topptr1;//defining a pointer variable to store address of the top node;

 


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
	int result = StackPeek(stack, &r);
		if(result == 0)
		{
			printf("peeking %d\n",r);
		}
		else
		{
			printf("Error in popping values");
		}
	for(i = 1; i < 6 ; i++)
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

Stack* stack=(Stack*)malloc(sizeof(Stack));//intializing the stack
topptr=stack;//equalising the top node 
stack->top=-1;//making it a empty stack
stack->next=NULL;

return stack;
}

int StackPush(Stack* stack, int value){
           Stack * current;//a temperory variable
           current=(Stack *)malloc(sizeof(Stack));//making a new node
           current->next=topptr;
           current->value=value;
           current->top++;
           topptr=current;//assigining the new top node
           
           
 return 0;
}

int StackPop(Stack* stack, int* value){
stack=topptr;//because we malloc one extra node in push
if(stack->top==-1){//underflow error
  

	return -1;}
else{
  *value=stack->value;
   stack->value='\0';//equalising the last element to NULL
   topptr=topptr->next;

	return 0;}

}
int StackPeek(const Stack* stack, int* value){
stack=topptr;
if(stack->top==-1){//underflow error
  return -1;}
else{*value=stack->value;
            
          return 0;}


}
	


int DeleteStack(Stack* stack){
 Stack * current;//a temperory variable
//if(sizeof(stack)==sizeof(Stack)) gave this error report because we h
 for(current=topptr;current!=NULL;current=current->next)

 	free(current);
 return 0;


}

Queue* CreateQueue(){
Queue* queue=(Queue*)malloc(sizeof(Queue));//intializing the queue
topptr1=queue;//equalising the top node 
queue->top=-1;//making it a empty stack
queue->next=NULL;


}

int QueueEnqueue(Queue* queue, int value);
          //a temperory variable
           Queue * current;=(Queue *)malloc(sizeof(Queue));//making a new node
           current->value=value;
           current->top++;
           queue=curret;
           queue->next=topptr1;//assigining the new top node
           topptr1=current;
           
 return 0;
}
