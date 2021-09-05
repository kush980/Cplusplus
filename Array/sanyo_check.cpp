#include<iostream>
using namespace std;
int kadane(int a[],int n)
{
	int cs=0,maxs2=0;
	for(int j=0;j<n;j++)
		{
			cs+=a[j];
			if(cs<0)
			cs=0;
			maxs2=max(cs,maxs2);
		}
		return maxs2;
}
int maxcircular(int a[],int n)
{
	int maxs=0,cur=0,c1=0;
	c1=kadane(a,n);
	for(int i=0;i<n;i++)
	{
		cur+=a[i];
		a[i]=-a[i];
	}
	cur=cur+kadane(a,n);
	maxs=max(cur,c1);
	return maxs;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[1000];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<maxcircular(a,n)<<endl;
		return 0;
	}
}