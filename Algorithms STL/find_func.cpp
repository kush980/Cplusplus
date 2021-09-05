#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={10,20,1,2,50};
    int n=sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    auto it=find(a,a+n,key);
    int index=it-a;
    if(index==n)
    {
        cout<<key<<" is not present"<<endl;
    }
    else
    {
        cout<<"key present at index "<<index<<endl;
    }
    return 0;
}