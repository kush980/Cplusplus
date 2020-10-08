#include<iostream>
#include<set>
#include<string>
using namespace std;

void permute(char *a,int i,set<string> &s)
{
    //base case
    if(a[i]=='\0')
    {
        string t(a);
        s.insert(t);
        return;
    }

    //recursive case
    for(int j=i;a[j]!='\0';j++)
    {
        swap(a[i],a[j]);

        //code written above the recursive call of the function are for downward movement in the tree after that its for the upward movement
        permute(a,i+1,s);
        swap(a[i],a[j]);
    }
}

int main()
{
    char a[1000];
    cin>>a;
    set<string> s;

    permute(a,0,s);
    for(auto str:s)
    {
        cout<<str<<" ";
    }
}