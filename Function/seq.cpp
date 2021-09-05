#include<iostream>
using namespace std;
int main() {
	long long n;
	int ans=0,b=1;
	while(n>0)
	{
		ans+=(n%8)*b;
		n=n/8;
		b=b*10;
	}
	cout<<ans;
	return 0;
}
