#include<stdio.h>
int fact(int n)
{
    if(n==0)
    return 1;
    return n*fact(n-1);
}

int fibo(int n)
{
    if(n==0 || n==1)
    return n;
    return fibo(n-1)+fibo(n-2);
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}


int main()
{
    int c,n,a,b;
    scanf("%d",&c);
   
    switch (c)
    {
    case 1:
          scanf("%d",&n);
          int ans=fact(n);
        printf("factorial of n is:%d",ans);
        break;
    case 2:
          scanf("%d",&n);
          int ans2=fibo(n);
        printf("fibo of n is :%d",ans2);
        break;
    case 3:
            scanf("%d",&a);
            scanf("%d",&b);
            int ans3=gcd(a,b);
        printf("gcd of a and b are :%d",ans3);
        break;
    default:
        break;
    }
}
