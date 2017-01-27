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
typedef struct _{
int value;
struct _* next;
int top;//variable to keep the node number
}node_t;


struct stack{//here a maxsize is not neccassary because  overflow is not possible in this implementation (unless memory is exhausted)

node_t  node;
node_t * topptr;

};
struct queue{
int top;
int value;
struct  queue * next;

}*tempnode,*quetopptr;//defining a pointer variable to temporary store a temporary addresses and a variable to keep the top variable in queue




int main(){
int i,r;

	printf("\nTesting Stack\n");

	Stack* stack = CreateStack();
	for(i = 1; i < 7; i++)
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
	int result = StackPeek(stack, &r);
		if(result == 0)
		{
			printf("peeking %d\n",r);
		}
		else
		{
			printf("Error in popping values\n");
		}
	for(i = 1; i < 6 ; i++)
	{
		 result = StackPop(stack, &r);
		if(result == 0)
		{
			printf("%d\n",r);
		}
		else
		{
			printf("Error in popping values \n");
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


	  DeleteStack(stack); 
	   

 

   /*  printf("Testing Queue\n");
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
	   result = QueuePeek(queue, &r);
		if(result == 0)
		{
			printf("peeking %d\n",r);
		}
		else
		{
			printf("Error in popping values");
		}
	
      DeleteQueue(queue);	*/
return 0;
}



Stack* CreateStack(){

Stack* stack=(Stack*)malloc(sizeof(Stack));//intializing the stack to keep  a  empty node at the end
stack->node.top=-1;//making it a empty stack
stack->node.next=NULL;
stack->topptr=&stack->node;//equalising the top node 

return stack;
}

int StackPush(Stack* stack, int value){
       if(stack->topptr->top+1==NO_OF_ELEMENTS){return -1;}
       else{    node_t * current;//a temperory variable
           current=(node_t *)malloc(sizeof(node_t));//making a new node
           current->next=stack->topptr;//assigning the previous node to current nodes next
           current->value=value;
           current->top++;
           stack->topptr=current;//assigining the new top node
           
           
 return 0;}
}

int StackPop(Stack* stack, int* value){

if(stack->topptr->top==-1){//underflow error
  

	return -1;}
else{
  *value=stack->topptr->value;
   stack->topptr->value='\0';//equalising the last element to NULL
   stack->topptr=stack->topptr->next;

	return 0;}

}
int StackPeek(const Stack* stack, int* value){

if(stack->topptr->top==-1 ){//underflow error
  return -1;}
else{*value=stack->topptr->value;
            
          return 0;}


}
	


int DeleteStack(Stack* stack){
 node_t * current;//a temperory variable

 for(current=stack->topptr;current!=&stack->node;current=current->next){//looping from the last node to the first nstack->topptr->next
 	free(current);}

 	free(stack);
 	
 return 0;


}

/*Queue* CreateQueue(){
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
      	
 return 0;
}

int QueueDequeue(Queue* queue, int* value){

queue=quetopptr;//to equalize queue to the node to be dequed
if(queue==NULL){//if no more nodes
   return -1;
}

else {*value=queue->value;
   queue->value='\0';//equalising the last element to NULL
   quetopptr=quetopptr->next;

	return 0;}

}
int QueuePeek(const Queue* queue, int* value){
queue=quetopptr;
if(queue==NULL){//if no node is left
  return -1;}
else{*value=queue->value;
            
          return 0;}




}

int DeleteQueue(Queue* queue){
 Queue * current;//a temperory variable


 for(current=queue;current!=NULL;current=current->next){

 	free(current);
 
}
quetopptr=current;//as i have given inputs to peek and  dequeue i have to update this as well
return 0;
}*/