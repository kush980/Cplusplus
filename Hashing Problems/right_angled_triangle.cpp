#include<iostream>
#include<unordered_map>
using namespace std;

int RightAngled(int n,int a[][2])
{
    unordered_map<int,int> hx,hy;
    for(int i=0;i<n;i++)
    {
        hx[a[i][0]]++;
        hy[a[i][1]]++;
    }

    int cnt=0;

    for(int i=0;i<n;i++)
    {
        if(hx[a[i][0]]>=1 && hy[a[i][0]]>=1)
        cnt+=(hx[a[i][0]]-1)*(hy[a[i][1]]-1);
    }
    return cnt;
}

int main()
{

    int n;
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
            cin>>a[i][j];
    }

    cout<<RightAngled(n,a)<<endl;

}