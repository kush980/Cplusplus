#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(j<=i)
		{
			cout<<j;
			j++;
		}
		for(int l=0;l<=(n-j);l++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
