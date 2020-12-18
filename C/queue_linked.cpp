#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int d)
{
	struct node* new_n;
	new_n = (struct node*)malloc(sizeof(struct node));
	new_n->data = d;
	new_n->next = NULL;
	if((front == NULL)&&(rear == NULL)){
		front = rear = new_n;
	}
	else{
		rear->next = new_n;
		rear = new_n;
	}
	
}
void print()
{
	struct node* temp;
	if((front == NULL)&&(rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		temp = front;
		while(temp){
			printf("\n%d",temp->data);
			temp = temp->next;
		}
	}
}
void dequeue()
{
	struct node *temp;
	temp = front;
	if((front == NULL)&&(rear == NULL)){
		printf("\nQueue is Empty");
	}
	else{
		front = front->next;
		free(temp);
	}
}
int main()
{
	int opt,n,i,data;
	while(opt!=0){
		printf("\n\n1. Insert \n2. Delete  \n3. Display \n4. Exit");
			printf("\nEnter Your Choice: ");

		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the size: ");
				scanf("%d",&n);
				printf("\nEnter the data: \n");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
				break;
		
			case 2:
				dequeue();
				break;
			case 3:
				print();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
	}
}
