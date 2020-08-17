#include<iostream>
using namespace std;
int main()
{
	int n1,n2;
	cin>>n1>>n2;
	int p=1;
	while(n1--)
	{
		if((3*p)+2%n2==0)
		{
		p=p+1;
		cout<<(3*p)+2<<endl;
	}
	else
	cout<<(3*p)+2<<endl;
	p=p+1;
	}
	return 0;
}
