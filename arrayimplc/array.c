#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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




typedef struct stack{
int top;
int  maxsize;
int stack_array[100000];

}stack;

int main(){
/*int i,r;
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
			printf("Error in pushing to stack \n");
		}
	}
for(i = 0; i < 5 ; i++)
	{
		int result = StackPop(stack, &i);
		if(result == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("Error in popping values \n");
		}
	}
	
	DeleteStack(stack);*/
int i,r,result;
	Stack* stack = CreateStack();
	for(i = 0; i < 100 ; i++)
	{
		// Generate a random value and put that to stack
		r = rand();	
		result = StackPush(stack, r);
		if(result != 0)
		{
			printf("Error in pushing to stack");
		}
	}

	for(i = 0; i < 100 ; i++)
	{
		result = StackPop(stack, &r);
		if(result != 0)
		{
			printf("Error in poping stack");
		}
	}
return 0;
}


stack* CreateStack(){

stack *stackptr=(stack*)malloc(sizeof(stack));
stackptr->top=0;
stackptr->maxsize=99;
return stackptr;
}

int DeleteStack(Stack* stack){

free(stack);


}

int StackPush(Stack* stack, int value){

if(value<(stack->maxsize)){
    stack->stack_array[stack->top]=value;
	stack->top++;
	return 0;
}
else {
    
	return -1;}

}


int StackPop(Stack* stack, int* value){

if(*value==stack->top){
 stack->stack_array[stack->top]='\0';
stack->top--;
	return 0;}
else{return -1;}


}