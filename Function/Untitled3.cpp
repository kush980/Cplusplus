#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int row=1;
	int col=2,n2=2;
	cout<<1<<endl;
	while(row<=n-1)
	{
//		if(n1)
//		cout<<1<<endl;
//		else
//		{
		cout<<col;
		while(n2<=row-2)
		{
		cout<<0;
		n2+=1;
		}
		cout<<col;
		col++;
		row++;
		cout<<endl;
	//	}

	}
	return 0;
}
