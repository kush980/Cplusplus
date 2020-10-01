#include <stdio.h>
#include <stdlib.h>
# define max 50
int queue[max];
int front=-1;
int rear=-1;
void insert( int );
void deletee();
void display();

int main()
{
	while(1)
	{
	 int choice;
	printf("\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				int val;
				printf("Enter the value to be entered\n");
				scanf("%d",&val);
				insert(val);
				break;
			}
	   case 2:
	   	{
	   		deletee();
	   		break;
		   }
		case 3:
		   	{
		   	display();
		   	break;
		   }
		case 4:exit(0);
		default:
		   	printf("Wrong Choice!!Please try again");		   	
	}		
  }
}
void insert(int val)
{
	if(rear==(max-1))
	printf("QUEUE OVERFLOW\n");
	else
	{
		if(front==-1)
		front=0;
	rear=rear+1;
	queue[rear]=val;
    }
}
void deletee()
{

	int val;
	if(front==-1||front>rear)
	printf("QUEUE UNDERFLOW\n");
	else
	{
	 val= queue[front];front++;
	printf("The deleted element is %d : \n",val);
    }
}
void display()
{
	int i;
		if(front==-1)
	printf("QUEUE IS EMPTY\n");
	else
	{
		printf("The QUEUE elements are:\n");
	for( i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}
}