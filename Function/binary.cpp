#include<iostream>
using namespace std;
int main() {
	long long n;
	int ans=0,p=1;
	cin>>n;
	while(n>0)
	{
		ans+=((n%10)*p);
		p=p*2;
		n=n/10;
	}
	cout<<ans<<endl;
	return 0;
}
