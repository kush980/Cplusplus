#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;


    node(int d)
    {
        data=d;
        next=NULL;
    }
};


//Functions(procedural programming)

void insertathead(node*&head,int d)         //passing the pointer by reference changes its value in main function too 
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }

    node *n=new node(d);
    n->next=head;
    head=n;
}

void print(node*head)           //passing the pointer by value so that its value in main doesnt change if we wanna print twice or more
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}


int length(node*head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

void insertattail(node*&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(data);
    return;
}

void insertatmiddle(node*&head,int data,int p)
{
    if(head==NULL || p==0)
    {
        insertathead(head,data);
    }
    else if(p>length(head))
    {
        insertattail(head,data);
    }
    else
    {
        int jump=1;
        node*temp=head;
        while(jump<=p-1)
        {
            temp=temp->next;
            jump++;
        }
        node*n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
    
}

void deletehead(node*&head)
{
    if(head==NULL)
    {
        return;
    }
    node*temp=head->next;
    delete head;
    head=temp;
}

//normal searching 

bool search(node*&head,int key)
{
    if(head==NULL)
    {
        return false;
    }
    while(head!=NULL)
    {
        if(head->data==key)
        return true;
        head=head->next;
    }
    return false;

}


//search recursively

bool recsearch(node*&head,int key)
{
    if(head==NULL)
    return false;

    if(head->data==key)
    return true;
    
    else
    {
        recsearch(head->next,key);
    }
    
}

node* take_input()
{
    int d;
    cin>>d;
    node*head=NULL;

    while(d!=-1)        //breaking condition
    {
        insertathead(head,d);
        cin>>d;
    }
    return head;
}

void reverse(node*&head)
{
    node*C=head;
    node*p=NULL;
    node*N;
    while(C!=NULL)
    {
        N=C->next;
        C->next=p;
        p=C;
        C=N;
    }
    head=p;
}

node* recreverse(node*head)
{
    if(head->next==NULL || head==NULL)
    {
        return head;
    }
    node*shead=recreverse(head->next);

    node*temp=head->next;
    temp->next=head;
    head->next=NULL;
    return shead;
}

node* midpoint(node*head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node*slow=head;
    node*fast=head->next;

    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}

//To merge the two sorted linked lists
node* merge(node*a,node*b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }

    node*c;

    if(a->data < b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
    
}


//sorting a unsorted linked list through mergesort\

node* mergesort(node*head)
{
    //base case
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    //recursive case
    //1. break the linked list from thew mid into 2 parts

    node*c;
    node*mid=midpoint(head);
    node*a=head;
    node*b=mid->next;

    mid->next=NULL;

    //2. recursively sort the broken linked list
    a=mergesort(a);
    b=mergesort(b);

    //3. merge the sorted linked list

    c=merge(a,b);
    return c;
}

int main()
{
    // node*head=NULL;

    
    node*head=take_input();
    //node*head_2=take_input();
    print(head);
    //print(head_2);

    //node* newhead=merge(head,head_2);
    node* sorted=mergesort(head);
    //print(newhead);
    print(sorted);

    //to get the reversed linked list
    // head = recreverse(head);
    // print(head);


    //to get the midpoint of the linked list
    // node* mid=midpoint(head);
    // cout<<mid->data<<endl;

    // insertathead(head,9);
    // insertathead(head,7);
    // insertathead(head,39);
    // insertathead(head,8);
    // insertathead(head,10);

    // print(head);
    // insertattail(head,90);
    // insertatmiddle(head,60,3);
    // print(head);
    // deletehead(head);
    // print(head);

    // int key;
    // cin>>key;
    // if(recsearch(head,key))
    // cout<<"Element present"<<endl;
    // else
    // {
    //     cout<<"Element Not present"<<endl;
    // }
    
}