#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *prev;
	struct node *next;	
};
struct node *insertatbeg(struct node *start, int x);
struct node *insertatend(struct node *start, int x);
struct node *insertatposition(struct node *start, int x,int k);
struct node *delatbeg(struct node *start);
struct node *delatend(struct node *start);
struct node *delatposition(struct node *start,int k);
void display(struct node *start);
int main()
{
	struct node *start=NULL;
	int ch,x,k;
	while(1)
	{
		printf("1.Insertion at beginning\n2.Insertion at end.\n3.Insertion at posiition.\n");
		printf("4.Deletion at beginning.\n5.Deletion at end.\n6.Deletion at specific position.\n");
		printf("7.Display\n8.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		if(ch==8)
		exit(1);
		switch(ch)
		{
			case 1:
				printf("Enter node: ");
				scanf("%d",&x);
				start=insertatbeg(start,x);
				break;
			case 2:
				printf("Enter node: ");
				scanf("%d",&x);
				start=insertatend(start,x);
				break;
			case 3:
				printf("Enter node: ");
				scanf("%d",&x);
				printf("Enter position: ");
				scanf("%d",&k);
				start=insertatposition(start,x,k);
				break;
			case 4:
				start=delatbeg(start);
				break;
			case 5:
				start=delatend(start);
				break;
			case 6:
				printf("Enter position: ");
				scanf("%d",&k);
				start= delatposition(start,k);
				break;
			case 7:
				display(start);
				break;			
			default:
				printf("INVALID CHOICE\n");
		}
	}
}
struct node *insertatbeg(struct node *start, int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=x;
	temp->next=temp->prev=NULL;
	if(start==NULL)
	{
		start=temp;
		return start;
	}
	temp->next=start;
	start=temp;
	return start;
}
struct node *insertatend(struct node *start, int x)
{
	struct node *temp, *p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=x;
	temp->next=temp->prev=NULL;
	if(start==NULL)
	{
		start=temp;
		return start;
	}
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
	temp->prev=p;
	return start;
}
struct node *insertatposition(struct node *start, int x,int k)
{
	struct node *temp, *p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=x;
	temp->next=temp->prev=NULL;
	int i;
	p=start;
	if(k==1)
	{
		temp->next=start;
		start=temp;
		return start;
	}
	for(i=1;i<k-1&&p!=NULL;i++)
	p=p->next;
	if(p==NULL)
	{
		printf("INVALID POSITION\n");
		return start;
}
		temp->prev=p;
	temp->next=p->next;
	p->next->prev=temp;
	p->next=temp;

	return start;
}
struct node *delatbeg(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("Empty list\n");
		return start;
	}
	if(start->next==NULL)
	{
		p=start;
		start=NULL;
		printf("The node to be deleted: %d \n",p->info);
		free(p);
		return start;
	}
	p=start;
	start=start->next;
	start->prev=NULL;
	printf("The node to be deleted: %d \n",p->info);
	free(p);
	return start;
	
}
struct node *delatend(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("Empty lsit\n");
		return start;
	}
	if(start->next==NULL)
	{
		p= start;
		printf("The node to be deleted: %d \n",p->info);
		start=NULL;
		free(p);
		return start;
	}
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->prev->next=NULL;
	printf("The node to be deleted: %d \n",p->info);
	free(p);
	return start;
}
struct node *delatposition(struct node *start,int k)
{
	struct node *p;
	int i;
	p=start;
	if(k==1)
	{
		start=delatbeg(start);
		return start;
	}
	for(i=2;i<=k&&p!=NULL;i++)
	{
		p=p->next;
	}
	if(p==NULL)
	{
		printf("INVALID POSITION\n");
		return start;
	}
	p->prev->next=p->next;
	p->next->prev=p->prev;
	printf("The node to be deleted: %d \n",p->info);
	free(p);
	return start;
}
void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("EMPTY LIST\n");
		return ;
	}
	p=start;
	printf("The list is: ");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}
