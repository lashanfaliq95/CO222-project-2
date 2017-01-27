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



struct stack{//here a maxsize is not neccassary because  overflow is not possible in this implementation (unless memory is exhausted)
int top;
int value;
struct stack* next;

}*topptr;//defining a pointer variable to store address of the top node

struct queue{
int top;
int value;
struct  queue * next;

}*tempnode,*quetopptr;//defining a pointer variable to temporary store stemporary addresses and a variable to the top variable in queue

 static int count=0;


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

     printf("Testing Queue\n");
	Queue* queue = CreateQueue();

	printf("Inserting values\n");
	for(i = 0; i < 5 ; i++)
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
     result = QueuePeek(queue, &r);
		if(result == 0)
		{
			printf("peeking %d\n",r);
		}
		else
		{
			printf("Error in popping values");
		}
	printf("Removing values\n");
	for(i = 0; i < 5	 ; i++)
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
return 0;
}



Stack* CreateStack(){

Stack* stack=(Stack*)malloc(sizeof(Stack));//intializing the stack to keep  a  empty node at the end
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
Queue* queue=(Queue*)malloc(sizeof(Queue));//intializing the queue using a empty node at the begining
tempnode=queue;//equalising to the temp node 
queue->top=-1;//making it a empty stack

return queue;

}

int QueueEnqueue(Queue* queue, int value){
           
           Queue* current;//a temperory variable
           current=(Queue *)malloc(sizeof(Queue));
           current->value=value;
           current->top++;
           current->next=NULL;
           tempnode->next=current;//assigining the new node to the  preivous next
           tempnode=current;//assigning the new node to the temp
           quetopptr=queue->next;//assigning the top in queue
           count++;
 return 0;
}

int QueueDequeue(Queue* queue, int* value){

queue=quetopptr;//to equalize queue to the node to be dequed
if(queue==NULL){
   return -1;
}

else {*value=queue->value;
   queue->value='\0';//equalising the last element to NULL
   quetopptr=quetopptr->next;

	return 0;}

}
int QueuePeek(const Queue* queue, int* value){
queue=quetopptr;
if(queue->top==-1){//underflow error
  return -1;}
else{*value=queue->value;
            
          return 0;}




}

int DeleteQueue(Queue* queue){
 Queue * current;//a temperory variable

//if(sizeof(stack)==sizeof(Stack)) gave this error report because we h
 for(current=queue;current->next!=NULL;current=current->next){

 	free(current);
 
}
quetopptr=current;//as i have given inputs to peek dequeue i have to update this as well
return 0;
}