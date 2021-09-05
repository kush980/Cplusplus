#include<iostream>
#include<vector>
#include<map>

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
        left=right=NULL;
    }
};

void verticalprint(node*root,int d,map<int,vector<int>>&m)
{
    //base case
    if(root==NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    verticalprint(root->left,d-1,m);
    verticalprint(root->right,d+1,m);
    return;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->right = new node(8);
    root->right->right->right = new node(9);

    map<int,vector<int>> m;
    int d=0;
    verticalprint(root,d,m);
    for(auto x:m)
    {
        for(auto s:x.second)
        {
            cout<<s<<",";
        }
        cout<<endl;
    }
}
