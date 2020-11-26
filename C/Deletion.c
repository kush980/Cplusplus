#include<stdio.h> 
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
int main()
{
	printf("Press 1 to delete from the beginning.\n");
	printf("Press 2 to delete from the end.\n");
	printf("Press 3 to delete from a specified position.\n");
	printf("Press 4 to display.\n");
	printf("Press 5 to exit.\n");
	int m,n,c,i=1,j,k;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	j=n;
	struct node *head,*temp,*imp;
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
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : if(head==NULL)
					 printf("Link List underflown.");
					 else
					 {
					 	 head=head->link;
					 	 j--;
					 }
					 break;
			case 2 : if(head==NULL)
					 printf("Link List is underflown.");
					 else
					 {
					 	 n=1;
					 	 temp=head;
					 	 while(n<j)
					 	 {
					 	 	 imp=temp;
							 temp=temp->link;
							 n++; 	 	 	
						 }
						 imp->link=NULL;
						 j--;
					 }
					 break;
			case 3 : if(head==NULL)
					 printf("Link List underflown.");
					 else
					 {
					 	 printf("Enter the position : ");
					 	 scanf("%d",&k);
					 	 n=1;
					 	 temp=head;
					 	 while(n<k)
					 	 {
					 	 	 imp=temp;
							 temp=temp->link;
							 n++; 	 	 		 	
						 }
						 imp->link=temp->link;
						 j--;
					 }
					 break;
			case 4 : if(head==NULL)
					 printf("Link List is empty.");
					 else
					 {
					 	imp=head;
					 	while(imp!=NULL)
					 	{				
							 printf("%d ",imp->data);
							 imp=imp->link;
						}	
					 	printf("\n");
					 }
					 break;
			case 5 : exit(0);
			default : printf("Wrong Choice.\n");
		}
	}
	return 0;
}
