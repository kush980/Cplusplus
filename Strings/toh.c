#include <stdio.h>
void tower(int,char,char,char);
int main()
{
	int n;
	printf("Enter the no. of disks");
	scanf("%d",&n);
	printf("The sequence of moves involved in the Tower of Hanoi are:\n");
	tower(n,'A','C','B');
	return 0;
	
}
void tower(int n,char beg,char end,char aux)
{
	if(n==1)
	{
		printf("\n Move disk 1 from peg %c to peg %c",beg,end);
		return;
	}
		tower(n-1,beg,aux,end);
		printf("\n Move disk %d from peg %c to peg %c",n,beg,end);
	    tower(n-1,aux,beg,end);
}