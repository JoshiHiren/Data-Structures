#include<iostream.h>
#include<conio.h>
void insert(int *top,int *rear,int stack[],int val)
{
	if(*rear==4)
	{
			cout<<"Stack is Overflow:";
	}
	else
	{
			(*rear)++;
			if(*rear==0);
			{
				*top=0;
			}
			stack[*rear]=val;
			cout<<stack[*rear]<<" is Inserted";

	}
}
void display(int *top,int *rear,int stack[])
{
	if(*rear==-1)
	{
		cout<<"!Stack is Empty";
	}
	else
	{
		for(int i=*rear;i>=*top;i--)
		{
			cout<<"\n"<<stack[i];
		}
	}
}
void pop(int *top,int *rear,int stack[])
{
	if(*rear==-1)
	{
		 cout<<"\nStack is Underflow";
	}
	else
	{
		int temp;
		temp=stack[*rear];
		(*rear)--;
		cout<<temp<<" Delted from the Stack ";
	}
}
void peek(int *top,int *rear,int stack[])
{
	if(*rear==-1)
	{
		cout<<"!!Nothing in Stack:";
	}
	else
	{
		cout<<stack[*rear]<<" is On top of THE stack";
	}
}
void main()
{
	int top=-1,rear=-1,choice,val,stack[5];
	do
	{
			cout<<"\n1.Push\n2.pop\n3.Peek\n4.Display\n5.Exit:";
			cout<<"\nEnter Your choice:";
			cin>>choice;

			switch(choice)
			{
				case 1:
					cout<<"\nEnter Value For Insert:";
					cin>>val;
					insert(&top,&rear,stack,val);
					break;
				case 2:
					pop(&top,&rear,stack);
					break;
				case 3:
					peek(&top,&rear,stack);
					break;
				case 4:
					display(&top,&rear,stack);
					break;
				default:
					cout<<"\n!Enter Valid Choice";
					break;
			}
				
	}while(choice!=5);
}
