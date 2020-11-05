#include <stdio.h>
#include <stdlib.h>
 typedef struct node Node;
struct Node {
  int item;
  struct Node* next;
};

void insertAtBeginning(struct Node** ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item = data;
  new_node->next = (*ref);
  (*ref) = new_node;
}

void insertAtEnd(struct Node** ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *ref;

  new_node->item = data;
  new_node->next = NULL;

  if (*ref == NULL) {
    *ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void printList(struct Node* node) {
  while (node != NULL) {
    printf(" %d ", node->item);
    node = node->next;
  }
}

int length(struct Node*head)
{
    int cnt=0;
    struct Node*t=head ;
    while(t!=NULL)
    {
        cnt++;
        t=t->next;
    }
    // printf("%d ||",cnt) ;
    return cnt;
}
struct Node* insert_at_pos(int pos,struct Node*head,int value)
{
    if(pos<=0) return head ;
    struct Node*t=head ;
    struct Node*prev=NULL  ;
    int k=pos ;
     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->item=value ;
    new_node->next=NULL ;
    while(k!=1 && t)
    {
        prev=t ;
        t=t->next ;
        k-- ;
    } 
    if(prev==NULL)
    {
        new_node->next=t ;
        return new_node ;
    }
    else
    {
        prev->next=new_node ;
        new_node->next=t ;
    }
    return head ;
}

int main() {
  struct Node* head = NULL;
    while(1)
	{
	 int choice;
	printf("\nEnter 1 to insert at head\nEnter 2 to insert at tail\nEnter 3 to insert at a specified positon\nEnter 4 to print\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
  switch(choice)
  {
      case 1 :
      {
      int no;
      scanf("%d",&no);
      insertAtBeginning(&head, no);
      break;
      }
      case 2:
      {
      int no_1;
      scanf("%d",&no_1);
      insertAtEnd(&head, no_1);
      break;
      }
      case 3:
      {
      int pos;
      int no_2;
      scanf("%d",&pos);
      scanf("%d",&no_2);
      struct Node* head1 =insert_at_pos(pos,head,no_2);
      printList(head1);
      break;
      }
      case 4:
        {
      printList(head);
      break;
        }
      default:
      printf("Wrong choice");
      exit(0);
}
}
}