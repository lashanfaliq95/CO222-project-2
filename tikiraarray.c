#include "StackAndQueue.h"
#define MAX_SIZE 100000
#include<stdlib.h>

struct stack{          //define the struct stack
int arr[MAX_SIZE];
int position;
};

struct queue{          //define the struct queue
int arr1[MAX_SIZE];
int position1;
int place1;
};


Stack* CreateStack()   //function for create stack
{
    Stack * Stack1=(Stack*)malloc(sizeof(Stack));
    Stack1->position=0;
    return Stack1;
}


int DeleteStack(Stack* stack)  //function for delete stack
{
    free(stack);
    return 0;
}

Queue* CreateQueue()     //function for create queue
{
    Queue * Queue1=(Queue*)malloc(sizeof(Queue));
    Queue1->position1=0;
    Queue1->place1=0;
    return Queue1;
}


int DeleteQueue(Queue* queue)   //function for delete queue
{
    free(queue);
    return 0;
}

int StackPush(Stack* stack, int value)   //function for push or input value for a defined stack
{
    if(stack->position>=MAX_SIZE)
    {
        return -1;
    }
    else
    {
        stack->arr[stack->position]=value;
        stack->position=stack->position+1;
        return 0;
    }
}



int StackPop(Stack* stack, int* value)   //function for pop or remove values from a defined stack
{
    if(stack->position<=0)
    {
        return -1;
    }
    else
    {
        *value=(stack->arr[stack->position-1]);
        //stack->arr[stack->position-1]=NULL;
        stack->position=stack->position-1;
        return 0;
    }
}


int StackPeek(const Stack* stack, int* value)   //function for viewing the next element to be removed in a defined stack
{
    if(stack->position<=0)
    {
        return -1;
    }
    else
    {
        (*value)=stack->arr[stack->position-1];
        return 0;
    }
}


int QueueEnqueue(Queue* queue, int value)      //function for push or input value for a defined queue
{
	int counter;
    if(queue->position1>=MAX_SIZE)
    {
        return -1;
    }
    else if(queue->place1==0)
    {
		queue->arr1[0]=value;
		queue->place1=queue->place1+1;
		return 0;
	}
	else
    {
        queue->position1=queue->position1+1;
            for(counter=queue->position1;counter>0;counter--)
            {
                queue->arr1[counter]=queue->arr1[counter-1];
            }
            queue->arr1[0]=value;
        return 0;
    }
}


int QueueDequeue(Queue* queue, int* value)     //function for pop or remove values from a defined queue
{
    if(queue->position1<0)
    {
        return -1;
    }
    else
    {
        *value=(queue->arr1[queue->position1]);
        //queue->arr1[queue->position1-1]=NULL;
        queue->position1=queue->position1-1;
        return 0;
    }
}



int QueuePeek(const Queue* queue, int* value)     //function for viewing the next element to be removed in a defined queue
{
    if(queue->position1<=0)
    {
        return -1;
    }
    else
    {
        *value=queue->arr1[queue->position1];
    }
}
