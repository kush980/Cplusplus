#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={10,20,1,2,12,24,100,500};
    int n=sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    bool binary=binary_search(a,a+n,key);
    if(binary)
    {
        cout<<"Present in the array"<<endl;
        //to get the index 
        //and to get the frequency
        // lower_bound will give the index that is >=key and upper bound will give the index that is >key
        auto lb=lower_bound(a,a+n,2);
        cout<<"lower bound of 2 is "<<(lb-a)<<endl;
        int *ub=upper_bound(a,a+n,2);
        cout<<"upper bound of 2 is "<<(ub-a)<<endl;
        cout<<"Frequency of 2 is "<<(ub-lb)<<endl;
    }
    else
    {
        cout<<"Absent";
    }
    return 0;
}