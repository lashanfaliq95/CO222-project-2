#include <stdio.h>
#include <stdlib.h>
#include "StackAndQueue.h"

int main()
{
	int i,r;
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
	
	DeleteStack(stack); 
	return 0;
}