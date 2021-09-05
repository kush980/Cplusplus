#include<stdio.h> 
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
int main()
{
	int a,b,c,d,e,j=1;
	printf("Press 1 to insert at the beginning.\n");
	printf("Press 2 to insert at the end.\n");
	printf("Press 3 to delete from the beginning.\n");
	printf("Press 4 to delete from the end.\n");
	printf("Press 5 to display.\n");
	printf("Press 6 to exit.\n");
	struct node *head=(struct node*)malloc(sizeof(struct node));
	struct node *temp,*next,*imp;
	printf("Enter the data for creating a node : ");
	scanf("%d",&d);
	if(head==NULL)
	{
		printf("Unable to allocate memory");
		exit(0);
	}
	head->data=d;
	head->link=NULL;
	temp=head;
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : printf("Enter the data : ");
					 scanf("%d",&d);
		 		 	 next=(struct node*)malloc(sizeof(struct node));
					 if(next==NULL)
					 printf("Unable to allocate memory");
					 else
					 {
						 next->data=d;
						 next->link=head;	
					     head=next;
					     temp->link=head;
					     j++;
				     }
					 break;
			case 2 : printf("Enter the data : ");
					 scanf("%d",&d);
					 next=(struct node*)malloc(sizeof(struct node));
					 if(next==NULL) 					
				 	 printf("Unable to allocate memory");
					 else
					 {
						 next->data=d;
				 		 next->link=head;
				 		 temp->link=next;
				 		 temp=next;
				 		 j++;
					 }
					 break;
			case 3 : if(j==0)
					 printf("Link List underflown.\n");
					 else
					 {
					 	 head=head->link;
					 	 temp->link=head;
					 	 j--;
					 }
					 break;
			case 4 : if(j==0)
					 printf("Link List underflown.\n");
					 else
					 {
					 	 a=1;
					 	 next=head;
					 	 while(a<j)
					 	 {
					 	 	 imp=next;
							 next=next->link;
							 a++; 	 	 	
						 }
						 imp->link=head;
						 temp=imp;
						 j--;
					 }
					 break;
			case 5 : if(j==0)
					 printf("Link List is empty.\n");
					 else
					 {
					 	a=1;
					 	next=head;
					 	while(a<=j)
					 	{				
							 printf("%d ",next->data);
							 next=next->link;
							 a++;
						}	
					 	printf("\n");
					 }
					 break;
			case 6 : exit(0);
			default : printf("Wrong Choice.\n");
		}
	}
	return 0;
}
