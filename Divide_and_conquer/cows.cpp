#include <iostream>
#include<algorithm>
using namespace std;

bool cows_2(long long int ar[],int n,int c,int mid)
{
	long long int next_cow=ar[0];
	
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(ar[i]-next_cow>=mid)
		{
			next_cow=ar[i];
			cnt++;
			if(cnt==c)
			{
				return true;
			}
		}
		
	}
	return false;
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		long long int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
        sort(a,a+n);
		long long int s=a[0];
		long long int e=a[n-1]-a[0];
        int ans=0;
        if(c==2)
        {
            ans=a[n-1]-a[0];
        }
		while(s<=e && c>2)
		{
			int mid=(s+e)/2;
			bool cows=cows_2(a,n,c,mid);
			if(cows)
			{
				ans=mid;
				s=mid+1;
			}
			else
			{
				e=mid-1;
			}
			
		}
        cout<<ans<<endl;
	}
    
	return 0;
}