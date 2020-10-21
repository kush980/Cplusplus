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

int main()
{
    // node*head=NULL;
    node*head=take_input();
    print(head);
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