#include<iostream>
using namespace std;
void selection_sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i;j<=n-1;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		swap(a[i],a[min]);
	}
}





int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	selection_sort(a,n);
	for(int j=0;j<n;j++)
	{
		cout<<a[j]<<" ";
	}
}
