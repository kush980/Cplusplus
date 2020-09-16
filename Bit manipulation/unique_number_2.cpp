#include<iostream>
using namespace std;


// void unique(int a[],int n)
// {
//     int result,pos,j=0;
//     for(int i=0;i<n-1;i++)
//     {
//         result=a[i]^a[i+1];
//     }
//     int temp=result;
//     while(result>0)
//     {
//         if(result&1)
//         {
//             pos=j;
//             break;
//         }
//         j++;
//     }
//     int mask=(1<<pos);
//     int x=0;
//     int y=0;
//     for(int i=0;i<n;i++)
//     {
//         if((a[i]&mask)>0)
//         {
//             x=x^a[i];
//         }
//     }
//     y=temp^x;
//     for(int i=0;i<=1;i++)
//     {
//         if(x>y)
//         {
//             cout<<x<<" "<<y;
//         }
//         else
//         {
//             cout<<y<<" "<<x;
//         }
        
//     }
// }
int main()
{
    int n;
    cin>>n;
    int no;
    int a[n];
    int result=0,pos=0;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        a[i]=no;
        result=a[i]^result;
    }
    int temp=result;
    while((temp&1)!=1)
    {
        pos++;
        temp=temp>>1;
    }
    int mask=(1<<pos);
    int x=0;
    int y=0;
    for(int i=0;i<n;i++)
    {
        if((a[i]&mask)>0)
        {
            x=x^a[i];
        }
    }
    y=result^x;
    cout<<min(x,y)<<" "<<max(x,y)<<endl;
        
}