#include<iostream>
using namespace std;
int main()
{
    int n,m,i=0;
    cin>>n>>m;
    int j=n-1;
    int a[n][m];
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<m;l++)
        {
            cin>>a[k][l];
        }
    }
    int key;
    cin>>key;
    int flag=0;
    while(i<n && j>0)
    {
        if(a[i][j]==key)
        {
            //cout<<"key found at"<<i<<" "<<j<<" ";
            flag++;
            break;
        }
        if(a[i][j]>key)
        {
            j--;
        }
        else if(a[i][j]<key)
        {
            i++;
        }
    }
    if(flag==1)
    cout<<"key present at "<<i+1<<","<<j+1<<endl;
    else
    cout<<"key not present";
return 0;
}



