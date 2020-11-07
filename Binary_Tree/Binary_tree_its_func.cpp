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


node* buildInorderfromPreorder(int *in,int*pre,int s,int e)
{
    static int i=0;
    if(s>e)
    {
        return NULL;
    }

    //rec case
    node*root = new node(pre[i]);
   int  index=-1;
    for(int j=s;s<=e;j++)
    {
        if(in[i]==pre[j])
        {
            index=j;
            break;
        }
    }

    i++;

    root->left = buildInorderfromPreorder(in,pre,s,index-1);
    root->right = buildInorderfromPreorder(in,pre,index+1,e);
    return root;
}


void Printrightview(node*root,int level,int &maxlevel)
{
    if(root==NULL)
    {
        return;
    }

    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel=level;
    }

    Printrightview(root->right,level+1,maxlevel);
    Printrightview(root->left,level+1,maxlevel);
}


node* lca(node*root,int a ,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a or root->data==b)
    {
        return root;
    }

    node*left = lca(root->left,a,b);
    node*right = lca(root->right,a,b);

    if(left!=NULL && right!=NULL)
    {
        return root;
    }

    if(left!=NULL)
    {
        return left;
    }
    return right;
}


// ublic:
//     int branchsum;
//     int maxsum;

//     pair()
//     {
//         branchsum=0;
//         maxsum=0;
//     }class pair
// {
// p,
    pair<int,int> maxsumpath(node*root)
    {
        pair<int,int> p;
        if(root==NULL)
        {
            return p;
        }

        pair<int,int> left = maxsumpath(root->left);
        pair<int,int> right = maxsumpath(root->right);

        int op1 = root->data;
        int op2 = left.first + root->data;
        int op3 = right.first + root->data;
        int op4 = left.first + right.first + root->data;

        int current_ans = max(op1,(max(op2,max(op3,op4))));

        p.first = max(left.first,max(right.first,0)) + root->data;
        p.second = max(left.second,max(right.second,current_ans));

        return p;
    }


int search(node*root,int key,int level)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==key)
    {
        return level;
    }

    int left = search(root->left,key,level+1);
    if(left!=-1)
    {
        return  left;
    }

    return search(root->right,key,level+1);
}

int distance_bw_twonodes(node*root,int a ,int b)
{
    node* lca_node = lca(root,a,b);
    int l1 = search(lca_node,a,0);
    int l2 = search(lca_node,b,0);
    return l1+l2;
}

int main()
{
    node*root = buildTree();
    // print(root);
    // cout<<endl;
    // printIn(root);
    // cout<<endl;
    // printPo(root);
    // cout<<endl;
    // printAlllevel(root);
    bfs(root);
    cout<<lca(root,1,14)<<endl;
    pair<int,int> p2 = maxsumpath(root);
    cout<<p2.first <<" "<<p2.second<<endl;
    cout<<distance_bw_twonodes(root,9,14)<<endl;
    // cout<<count(root)<<endl;
    // cout<<sum(root)<<endl;
    // cout<<diameter(root)<<endl;
    // pair<int,int> p1= diameter_opt(root);
    // cout<<p1.first<<endl;
    // cout<<p1.second<<endl;
    // cout<<max(p1.first,p1.second)<<endl;
    // replace_sum(root);
    // bfs(root);
    //input = 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    // if(balance(root).second)
    // {
    //     cout<<"balanced tree"<<endl;
    // }
    // else
    // {
    //     cout<<"not a balanced tree"<<endl;
    // }
    
    // int a[ ]={1,2,3,4,5,6,7};
    // int n=7;

    // node*root=builttreefromarray(a,0,n-1);
    // bfs(root);


    // int in[] = {3,2,8,4,1,6,7,5};
    // int pre[] = {1,2,3,4,8,5,6,7};

    // int n=sizeof(in)/sizeof(int);

    // node*root=buildInorderfromPreorder(in,pre,0,n-1);
    // bfs(root);
    // node*root=NULL;
    // // cin>>root;
    // cout<<root<<endl;
    // int maxlevel=-1;
    // Printrightview(root,0,maxlevel);

}