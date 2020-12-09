#include<iostream>
using namespace std;

class node
{
public:
    node*left;   //for 0
    node*right; //for 1
};

class trie
{
    node*root;
public:
    trie()
    {
        root = new node();
    }

    void insert(int n)
    {
        node*temp = root;

        for(int i=31;i>-0;i--)
        {
            int bit=(n>>i)&1;
            if(bit==0)
            {
                if(temp->left==NULL)
                temp->left = new node();
                temp = temp->left;
            }
            else
            {
                if(temp->right==NULL)
                temp->right = new node();
                temp = temp->right;
            }
            
        }
    }
    //Help function for max xor
    int max_xor_help(int value)
    {
        int curr = 0;
        node*temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit = (value>>i)&1;

            if(bit==0)
            {
                //find the complementary bit
                if(temp->right!=NULL)
                {
                    temp = temp->right;
                    curr+= (1<<i); 
                }
                else 
                {
                    temp = temp->left;
                }
            }
            else
            {
                if(temp->left!=NULL)
                {
                    temp = temp->left;
                    curr+=(1<<i);
                }
                else
                {
                    temp = temp->right;
                }
                
            }
 
        }
        return curr;
    }

    int max_xor(int *input,int n)
    {
        int max1 = 0;
        for(int i=0;i<n;i++)
        {
            int val = input[i];
            insert(val);
            int current = max_xor_help(val);
            max1 = max(current,max1);
        }
        return max1;
    }
};

int main()
{
    int n;
    cin>>n;
    int a[n];
    trie t;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<t.max_xor(a,n)<<endl;
}