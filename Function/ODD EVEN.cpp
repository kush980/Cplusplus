#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	while(n--)
	{
		int no;
		cin>>no;
		int a=0,b=0,l;
		while(no>0)
		{
           l=no%10;
		   if(l%2==0)
		   {
			   b+=l;
		   }
		   else
		   {
			   a+=l;
		   }
		   no=no/10;
		}
		if(b%4==0 || a%3==0)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}
