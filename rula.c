
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "StackAndQueue.h"

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
typedef struct _{
				int num;
				int error;
				int count;
				struct _* next;
			} Node;
			

struct stack{
	         Node node;
	         Node *tos;
			 };

struct queue{
	        Node node;
	        Node *toq;
	        Node *previous; 
			 };
			 
	 //top of stack
	 //top  of queue

int main(){
int i,r;

  printf("\nTesting Stack\n");

  Stack* stack = CreateStack();
 for(i = 1; i < 6; i++)
  {
    int result = StackPush(stack, i);
    if(result == 0)
    {
      printf("%d \n",i);
    }
    else
    {
      printf("Error in pushing to  stack \n");
    }
  }
      

  int result = StackPeek(stack, &r);
    if(result == 0)
    {
      printf("peeking %d\n",r);
    }
    else
    {
      printf("Error in popping values\n");
    }
     
  for(i = 1; i < 7; i++)
  {
    int result = StackPop(stack, &r);
    if(result == 0)
    { 
      printf("%d\n",r);
    }
    else
    {
      printf("Error in popping values\n");
    }
  }
   result = StackPeek(stack, &r);
    if(result == 0)
    {
      printf("peeking %d\n",r);
    }
    else
    {
      printf("Error in peeking values\n");
    }

    
      DeleteStack(stack);
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
      printf("Error in popping values\n");
    }
   
  printf("Removing values\n");
  for(i = 0; i < 5   ; i++)
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

     result = QueuePeek(queue, &r);
    if(result == 0)
    {
      printf("peeking %d\n",r);
    }
    else
    {
      printf("Error in popping values\n");
    }
DeleteQueue(queue);
      
return 0;
}
Stack* CreateStack() {
	
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	
	stack->node.next=NULL;
	stack->node.error=-1;
	
	 stack->tos =&stack->node;
	return stack; 			 
	
}		 
			 
int DeleteStack(Stack* stack) {
	Node *temp;
	
	
	temp=stack->tos;
	while(temp!=NULL){
	
	temp=stack->tos->next;
	free(stack->tos);
	stack->tos=temp;
	
}
   free(stack);
	return 0;
	}
	
int StackPush(Stack* stack, int value){
	
	Node *current;
	current =(Node *)malloc(sizeof(Node));
	current->num = value;
	current -> next =stack->tos;
	stack->tos=current;
	
	return 0;
}

int StackPop(Stack* stack, int* value) {
	
	Node *temp_node;
	if(stack->tos==NULL)
	return -1;
	
	else if(stack->tos->next==NULL)
	return -1;
	
	else{
	
	
	*value = stack->tos->num;
	temp_node=stack->tos;
	
	stack->tos=stack->tos->next;

	free(temp_node);
	return 0; 
}
	
	
	}
	
int StackPeek(const Stack* stack, int* value){
	if(stack->tos==NULL)
	return -1;
	
	else if(stack->tos->next==NULL)
	return -1;
	
	else{
	*value = stack->tos->num;
    
    return 0;
	}	
}
	
	
Queue* CreateQueue(){
	
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	
	queue->previous=&queue->node;
	queue->node.count=0;
	queue->node.error=-1;
	
	return queue; 
	
	}
int DeleteQueue(Queue* queue){
	Node *temp;
	
	
	
	while(queue->node.count!=0){
	
	temp=queue->toq->next;
	
	free(queue->toq);
	queue->toq=temp;
	queue->node.count--;
}
   free(queue);
	return 0; 
	}	
	
int QueueEnqueue(Queue* queue, int value){
	Node *current;
	current =(Node *)malloc(sizeof(Node));
	
	current->num = value;
	
	current -> next =NULL;
	queue->previous->next=current;
	
	queue->previous=current;
	queue->toq=queue->node.next;
	queue->node.count++;
	return 0; 
	}
int QueueDequeue(Queue* queue, int* value){
    Node *temp_node;
	if(queue->toq==NULL)
	return -1;
	temp_node=queue->toq;
	*value = queue->toq->num;
	
	
	queue->toq=queue->toq->next;
	free(temp_node);
    queue->node.count--;
	return 0;} 
	
int QueuePeek(const Queue* queue, int* value){
	if(queue->toq==NULL)
	return -1;
	
	else{
	*value = queue->toq->num;
}
	
	return 0;
}
