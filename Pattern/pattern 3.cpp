#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			cout<<"\t";
		}
		int a=i;
		for(int l=1;l<=i;l++)
		{
			cout<<a<<"\t";
			a++;
		}
		//a=a-2;
		for(int m=1;m<=i-1;m++)
		{
			a--;
			cout<<a<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
