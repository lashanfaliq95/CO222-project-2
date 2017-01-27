#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "StackAndQueue.h"
#define MAX_SIZE 100000


typedef struct _{
int val;
int counter;
struct _* next;
}node;


struct stack{          //define the struct stack
node place;
node * finalp;
};


struct queue{          //define the struct queue
node place1;
node *finalp1;
};


/*int main(){
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
     
  for(i = 1; i < 4; i++)
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
 /* Queue* queue = CreateQueue();

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
}*/
Stack* CreateStack()   //function for create stack
{
    Stack * Stack1=(Stack*)malloc(sizeof(Stack));
    Stack1->place.counter=0;
    Stack1->finalp=&(Stack1->place);
    return Stack1;
}


int DeleteStack(Stack* stack)  //function for delete stack
{
    int count;
    node* current;
    for(count=stack->finalp->counter;count>=0;count--)
    {
        current=stack->finalp;
        stack->finalp=stack->finalp->next;
        free(current);
    }
    //stack->counter=0;
    //free(stack);
    return 0;
}


Queue* CreateQueue()     //function for create queue
{
    Queue * Queue1=(Queue*)malloc(sizeof(Queue));
    Queue1->place1.counter=0;
    Queue1->finalp1=&(Queue1->place1);
    return Queue1;
}


int DeleteQueue(Queue* queue)   //function foe delete queue
{
    int count;
    node* current;
    for(count=queue->finalp1->counter;count>=0;count--)
    {
        current=queue->finalp1;
        queue->finalp1=queue->finalp1->next;
        free(current);
    }
    //stack->counter=0;
    //free(stack);
    return 0;
}



int StackPush(Stack* stack, int value)   //function for push or input value for a defined stack
{
        node* current=(node*)malloc(sizeof(node));
        current->val=value;
        current->next=stack->finalp;
        current->counter=(stack->finalp->counter)+1;
        stack->finalp=current;
        return 0;
}




int StackPop(Stack* stack, int* value)   //function for pop or remove values from a defined stack
{node * current;
    if(stack->finalp->counter<=0)
    {
        return -1;
    }
    else
    {
        *value=stack->finalp->val;
        current=stack->finalp->next;
        free(stack->finalp);
        stack->finalp=current;
        //free(stack);

        return 0;
    }
}



int StackPeek(const Stack* stack, int* value)   //function for viewing the next element to be removed in a defined stack
{
    if(stack->finalp->counter<=0)
    {
        return -1;
    }
    else
    {
        *value=stack->finalp->val;
        return 0;
    }
}



/*int QueueEnqueue(Queue* queue, int value)      //function for push or input value for a defined queue
{
    int count;
    node* temp;
    Queue* fake;
    fake=queue;

        node * current=(node*)malloc(sizeof(node));
        current->val=value;
        current->counter=1;
        for(count=queue->finalp1->counter;count>0;count--)
        {
            if(count!=1)
            {
               fake->finalp1->counter=fake->finalp1->counter+1;
               temp=fake->finalp1->next;
               fake=temp;
            }
            else
            {
               fake->finalp1->counter=fake->finalp1->counter+1;
            }
        }

        fake->finalp1=current->next;

        if(queue->finalp1->counter==0)
        {
            queue->finalp1->counter++;
        }
        return 0;
}




int QueueDequeue(Queue* queue, int* value)
{
    if(queue->finalp1->counter<=0)
    {
        return -1;
    }
    else
    {
        *value=queue->finalp1->val;
        queue->finalp1=queue->finalp1->next;
        free(queue->finalp1);
        //free(stack);

        return 0;
    }
}



int QueuePeek(const Queue* queue, int* value)
{
    if(queue->finalp1->counter<=0)
    {
        return -1;
    }
    else
    {
        *value=queue->finalp1->val;
        return 0;
    }
}
*/




