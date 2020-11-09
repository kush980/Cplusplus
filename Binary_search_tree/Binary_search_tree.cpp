#include<iostream>
#include<queue>
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


int main()
{
    node*root = build();

    inorder(root);
    cout<<"\n";
    bfs(root);
}