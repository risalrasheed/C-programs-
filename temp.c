#include<stdio.h>
#define SIZE 10
#define TRUE 1
void display(int stack_num,int stack_size, int*stack, int*stack_ptr)
{
	int i;
	printf("Stack %d is ",stack_num);
	for(i=(stack_num-1)*stack_size;i<=stack_ptr[stack_num-1];i++)
		printf("%d ",stack[i]);
}

int divide (int * stack_ptr, int size, int n)
{
	int stack_size=size/n;
	int i=0;
	for(i=0; i<n; i++)
		stack_ptr[i]=i*stack_size-1;
	return stack_size;
}

void push(int *stack,int* stack_ptr, int stack_size)
{
	int stack_num;
	printf("Enter the stack number ");
	scanf("%d",&stack_num);
	if(stack_ptr[stack_num-1]==stack_num*stack_size-1)
		printf("Overflow ");
	else
	{
		printf("Enter the numbe to push ");
		scanf("%d",&stack[++stack_ptr[stack_num-1]]);
		display(stack_num,stack_size,stack,stack_ptr);
	}
}

void pop(int* stack_ptr, int* stack, int stack_size)
{
	int stack_num;
	printf("Enter the stack number ");
	scanf("%d",&stack_num);
	if(stack_ptr[stack_num-1]==(stack_num-1)*stack_size-1)
		printf("Underflow");
	else
		--stack_ptr[stack_num-1];
	display(stack_num,stack_size,stack,stack_ptr);
}

void menu()
{
	printf("1)Push\n");
	printf("2)Pop\n");
	printf("3)Exit\n");
}

void main()
{	
	int n;
	int opt;
	int flag=1;
	int stack[SIZE];
	int stack_ptr[SIZE];
	int stack_size;
	printf("Enter the number of stacks needed ");
	scanf("%d",&n);
	stack_size=divide(stack_ptr,SIZE,n);
	while(flag)
	{
		menu();
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				push(stack, stack_ptr,stack_size);
				break;
			case 2:
				pop(stack_ptr, stack, stack_size);
				break;
			case 3:
				flag=0;
				break;
			default:
				continue;
		}
	}
}
