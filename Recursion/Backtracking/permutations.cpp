#include<iostream>
using namespace std;

void permute(char *a,int i)
{
    //base case
    if(a[i]=='\0')
    {
        cout<<a<<" ";
        return;
    }

    //recursive case
    for(int j=i;a[j]!='\0';j++)
    {
        swap(a[i],a[j]);

        //code written above the recursive call of the function are for downward movement in the tree after that its for the upward movement
        permute(a,i+1);
        swap(a[i],a[j]);
    }
}

int main()
{
    char a[1000];
    cin>>a;

    permute(a,0);
}