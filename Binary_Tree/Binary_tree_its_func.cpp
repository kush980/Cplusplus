#include<iostream>
#include<queue>
#include<utility>
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

int height(node*root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lf=height(root->left);
    int rf=height(root->right);
    return max(lf,rf)+1;
}

void printKthLevel(node*root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;
}

void printAlllevel(node*root)
{
    int h = height(root);

    for(int i=1;i<=h;i++)
    {
        printKthLevel(root,i);
        cout<<endl;
    }
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


int count(node*root)
{
    if(root==NULL)
    {
        return 0;
    }

    return 1+count(root->left)+count(root->right);
}


int sum(node*root)
{
    if(root==NULL)
    {
        return 0;
    }

    return root->data + sum(root->left)+sum(root->right);
}


int diameter(node*root)
{
    if(root==NULL)
    {
        return 0;
    }


    int h1=height(root->left);
    int h2=height(root->right);
    int d=h1+h2;
    int ld=diameter(root->left);
    int rd=diameter(root->right);

    return max(d,max(ld,rd));
}


pair<int,int> diameter_opt(node*root)
{
    pair<int,int> p;
    if(root==NULL)
    {
        p.first=p.second=0;
        return p;
    }

    pair <int,int> left = diameter_opt(root->left);
    pair <int,int> right = diameter_opt(root->right);

    p.first=max(left.first,right.first)+1;
    p.second = max(left.first+right.first,max(left.second,right.second));
    return p;
}


int replace_sum(node*root)
{
    if(root==NULL)
    {
        return 0;
    }

    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }

    int ls=replace_sum(root->left);
    int rs=replace_sum(root->right);

    int temp=root->data;
    root->data=ls+rs;
    return temp+root->data;
}


pair<int,bool> balance(node*root)
{
    pair<int,bool> p;
    if(root==NULL)
    {
        p.first=0;
        p.second=true;
        return p;
    }

    pair<int,bool> left=balance(root->left);
    pair<int,bool> right=balance(root->right);

    p.first=max(left.first,right.first)+1;

    if(abs(left.first-right.first)<=1 && left.second && right.second)
    {
        p.second=true;
    }
    else
    {
        p.second=false;
    }
    


}

node* builttreefromarray(int *a,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }

    int mid=(s+e)/2;
    node*root=new node (a[mid]);
    root->left=builttreefromarray(a,s,mid-1);
    root->right=builttreefromarray(a,mid+1,e);

    return root;
}

int main()
{
    // node*root = buildTree();
    // print(root);
    // cout<<endl;
    // printIn(root);
    // cout<<endl;
    // printPo(root);
    // cout<<endl;
    // printAlllevel(root);
    // bfs(root);
    // cout<<count(root)<<endl;
    // cout<<sum(root)<<endl;
    // cout<<diameter(root)<<endl;
    // pair<int,int> p1= diameter_opt(root);
    // cout<<p1.first<<endl;
    // cout<<p1.second<<endl;
    // cout<<max(p1.first,p1.second)<<endl;
    // replace_sum(root);
    // bfs(root);
    // if(balance(root).second)
    // {
    //     cout<<"balanced tree"<<endl;
    // }
    // else
    // {
    //     cout<<"not a balanced tree"<<endl;
    // }
    
    int a[ ]={1,2,3,4,5,6,7};
    int n=7;

    node*root=builttreefromarray(a,0,n-1);
    bfs(root);
}