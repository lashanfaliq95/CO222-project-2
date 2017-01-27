#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "StackAndQueue.h"

#define NO_OF_ELEMENTS 100000


typedef struct _{
int value;
struct _* next;
}node_t;


struct stack{//here a maxsize is not neccassary because  overflow is not possible in this implementation (unless memory is exhausted)

node_t  node;//the variable to keep the  empty node which will be at the end of the list
node_t * topptr;//variable to keep the node which is always at the top

};

struct queue{//here a maxsize is not neccassary because  overflow is not possible in this implementation (unless memory is exhausted)
node_t  node;//the variable to keep the  empty node which will there at the begining of the list
node_t * tempnode;
node_t * quetopptr;//the variable to keep the node to be removed next

};


Stack* CreateStack(){//creating the stack

Stack* stack=(Stack*)malloc(sizeof(Stack));//intializing the stack to keep  a  empty node at the end
stack->topptr=NULL;

return stack;

}

int StackPush(Stack* stack, int value){//adding elements to the stack
       
           node_t * current;//a temparory variable
           current=(node_t *)malloc(sizeof(node_t));//making a new node
           current->next=stack->topptr;//assigning the previous node to current nodes next
           current->value=value;
           stack->topptr=current;//assigining the new top node
           
           return 0;
       }


int StackPop(Stack* stack, int* value){//popping elements from the stack
node_t* current;//a temperory variable

if(stack->topptr==NULL ){//underflow error
       return -1;}
else{
  *value=stack->topptr->value;
   current=stack->topptr->next;//giving the next top to current
   free(stack->topptr);
   stack->topptr=current;
   
      return 0;}

}

int StackPeek(const Stack* stack, int* value){//checking the next element to be popped

if(stack->topptr==NULL ){//underflow error
  return -1;}
else{*value=stack->topptr->value;
             return 0; }
}
  
int DeleteStack(Stack* stack){//deleting the stack
 node_t * current;//a temperory variable
if(stack->topptr==NULL){//if no nodes 
  
  free(stack); 

  return 0;
}
 else{ current=stack->topptr;
  
  while(current!=NULL){
     current=stack->topptr->next;
     free(stack->topptr);
     stack->topptr=current;    
    }   
    free(stack);    
    
    return 0;
  } 
}


Queue* CreateQueue(){//creating the queue
Queue* queue=(Queue*)malloc(sizeof(Queue));//intializing the queue using a empty node at the begining
queue->tempnode=&queue->node;//equalising to the temp node 

return queue;

}

int QueueEnqueue(Queue* queue, int value){//adding elements
           
           node_t* current;//a temperory variable
           current=(node_t *)malloc(sizeof(node_t));
           current->value=value;
           current->next=NULL;
           queue->tempnode->next=current;//assigining the new node to the  preivous next
           queue->tempnode=current;//assigning the new node to the temp
           queue->quetopptr=queue->node.next;//assigning the top in queue
        
 return 0;
}

int QueueDequeue(Queue* queue, int* value){//removing elements
 node_t* current;//a temperory variable

if(queue->quetopptr==NULL){//if no more nodes
   return -1;
}

else {*value=queue->quetopptr->value;
   current=queue->quetopptr->next;
   free(queue->quetopptr);
   queue->quetopptr=current;
  return 0;}

}
int QueuePeek(const Queue* queue, int* value){//checking the next element to be removed

if(queue->quetopptr==NULL){//if no node is left
  return -1;}
else{*value=queue->quetopptr->value;
            
          return 0;}
}

int DeleteQueue(Queue* queue){//deleting the queue
 
node_t * current;//a temperory variable
node_t * temp;
 
 current=queue->quetopptr;
  
  while(current!=NULL){
     temp=current->next;
     free(current);
       current=temp;    
    }

  free(queue);
  
return 0;
}