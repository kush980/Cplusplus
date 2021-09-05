#include<iostream>
using namespace std;
int main()
{
    int n;
    int no;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
	
        cin>>no;
        ans=ans^no;
}
    cout<<ans<<endl;
    return 0;
}
