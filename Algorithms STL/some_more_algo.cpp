#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a=10;
    int b=20;
    swap(a,b);      // will swap the values , can also be used in arrays
    cout<<a<<" "<<b<<endl;

    cout<<max(a,b)<<endl;       //will print the max element between the two 
    cout<<min(a,b)<<endl;       // will print the minimum element of the two 

    int ar[]={1,2,3,4,5};
    reverse(ar,ar+3);         // will reverse the array from index 0 to 3 

    int n=sizeof(ar)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;

    next_permutation(ar,ar+n);
     for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
}