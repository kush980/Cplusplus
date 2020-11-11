#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class node
{
    public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};


node* insertInBST(node*root,int data)
{
    //base case
    if(root==NULL)
    {
        return new node(data);
    }

    //recursive case
    if(data<=root->data)
    {
        root->left = insertInBST(root->left,data);
    }
    else
    {
       root->right =  insertInBST(root->right,data);
    }
    return root;
    
}

node* build()
{
    //base case
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1)        //breaking condition
    {
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;

}

void bfs(node*root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node*a=q.front();
        if(a==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
        cout<<a->data<<" ";
        q.pop();

        if(a->left)
        {
            q.push(a->left);
        }
        if(a->right)
        {
            q.push(a->right);
        }
        }
    }
    return;
}


void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}
void printPo(node*root)
{
    if(root==NULL)
    {
        return;
    }

    //otherwise , print in the postorder(left,right,root)
    printPo(root->left);
    printPo(root->right);
    cout<<root->data<<" ";
}


bool search(node*root,int data)
{
    //breaking case
    if(root==NULL)
    {
        return false;
    }
    
    if(root->data==data)
    {
        return true;
    }

    if(data<=root->data)
    {
        search(root->left,data);
    }

    else
    {
        search(root->right,data);
    }
    
    // return false;
}

node* deleteInBST(node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(data<root->data)
    {
        root->left = deleteInBST(root->left,data);
        return root;
    }
    else if(data==root->data)
    {
        //when root has no children
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        //when root has one children
        if(root->left!=NULL && root->right==NULL)
        {
            node*temp=root->left;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL)
        {
            node*replace=root->right;
            //find the inorder successor from right subtree

            while(replace->left!=NULL)
            {
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            return root;
        }
    }
    else
    {
        root->right = deleteInBST(root->right,data);
        return root;
    }
    
}

bool isBST(node*root,int minv=INT_MIN,int maxv=INT_MAX)
{
    if(root==NULL)
    {
        return true;
    }

    if(root->data>-minv && root->data<=maxv && isBST(root->left,minv,root->data) && isBST(root->right,root->data,maxv))
    {
        return true;
    }
    return false;
}

class linkedlist
{
    public:
    node*head;
    node*tail;

};

linkedlist flatten(node*root)
{
    linkedlist l;

    if(root==NULL)
    {
        l.head=l.tail=NULL;
        return l;
    }

    //leaf node
    if(root->left==NULL && root->right==NULL)
    {
        l.head=l.tail=root;
        return l;
    }

    //left is not null
    if(root->left!=NULL && root->right==NULL)
    {
        linkedlist leftll = flatten(root->left);
        leftll.tail->right=root;

        l.head=leftll.head;
        l.tail=root;
        return l;
    }

    //right is not null
    if(root->left==NULL && root->right!=NULL)
    {
        linkedlist rightll = flatten(root->right);
        root->right = rightll.head;

        l.head=root;
        l.tail  = rightll.tail;
        return l;
    }

    //when both ate not null
    linkedlist leftll = flatten(root->left);
    linkedlist rightll = flatten(root->right);

    leftll.tail->right = root;
    root->right = rightll.head;

    l.head =leftll.head;
    l.tail = rightll.tail;
    return l;

}

int main()
{
    node*root = build();

    inorder(root);
    cout<<"\n";
    bfs(root);
    printPo(root);

    // int k;
    // cin>>k;
    // if(search(root,k))
    // {
    //     cout<<"element is presernt";
    // }
    // else
    // {
    //     cout<<"element is not present";
    // }

    // root = deleteInBST(root,k);
    // bfs(root);
    // cout<<endl;
    // if(isBST(root))
    // {
    //     cout<<"A bST";
    // }
    // else
    // {
    //     cout<<"not a BST";
    // }
    cout<<endl;
    linkedlist l1 = flatten(root);
    node*temp = l1.head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->right;
    }

    cout<<endl;
}