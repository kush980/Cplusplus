#include<iostream>
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

node*buildTree()
{
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }

    node*root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root; 
}

void print (node*root)
{
    if(root==NULL)
    {
        return;
    }

    //if not NULL , then print the subtrees along woth root
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);

}

void printIn(node*root)
{
    if(root==NULL)
    {
        return;
    }

    //otherwise , print in the inorder (left,root,right)
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
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

int main()
{
    node*root = buildTree();
    print(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printPo(root);
    cout<<endl;
}