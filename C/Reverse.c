#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
int main()
{
	int m,n,i=1;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	struct node *head,*temp,*prevNode,*curNode;
	head=(struct node *)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("Unable to allocate memory");
		exit(0);
	}
	printf("Enter Data %d : ",i);
	scanf("%d",&m);
	head->data=m;
	head->link=NULL;
	temp=head; 
	for(i=2;i<=n;i++)
	{
		struct node *bottom=(struct node *)malloc(sizeof(struct node));
		if(bottom==NULL)
		printf("Unable to allocate memory");
		else
		{
			printf("Enter Data %d : ",i);
			scanf("%d",&m);
			bottom->data=m;
			bottom->link=NULL;
			temp->link=bottom;
			temp=temp->link;
		}
	}
	prevNode=head;
	curNode=head->link;
	head=head->link;
	prevNode->link=NULL;
	while(head!=NULL)
	{
		head=head->link;
		curNode->link=prevNode;
		prevNode=curNode;
		curNode=head;
	}
	head=prevNode;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ->",temp->data);
		temp=temp->link;
	}
	return 0;
}
