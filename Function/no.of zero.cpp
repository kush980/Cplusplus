#include<iostream>
using namespace std;
int zero(int n){
	int cnt=0;
	for(int i=5;n/i>=1;i*=5)
	{
			n=i*1;
	}
	return n;
}
int main()
{
	int n,l=0;
	cin>>n;
	fact(n);
	while(n>0)
	{
		if((n%10)==0){
		
		n=n/10;
		l++;
	}
	else 
	return 0;
	}
	cout<<l;
}
