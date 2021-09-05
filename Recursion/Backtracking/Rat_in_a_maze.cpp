#include<iostream>
using namespace std;

bool ratinamaze(char in[10][10],int out[][10],int i,int j,int m,int n)
{
    //base case
    if(i==m && j==n)
    {
        out[m][n]=1;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<out[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //recursive case
    //check case
    if(i>m || j>n)
    return false;
    if(in[i][j]=='X')
    return false;
    out[i][j]=1;            // considering the solution exists;
    bool rightsuccess = ratinamaze(in,out,i,j+1,m,n);
    bool downsuccess = ratinamaze(in,out,i+1,j,m,n);

    // backtracking         making the path zero to find the different path
    out[i][j]=0;


    if(rightsuccess || downsuccess)
    {
        return true;
    }
    return false;

}

int main()
{
    char in[10][10]={
                    "0000",
                    "00X0",
                    "000X",
                    "0X00"
                            };
    int out[10][10]={0};
    int m=4,n=4;
    bool ans = ratinamaze(in,out,0,0,m-1,n-1);
    if(ans==false)
    {
        cout<<"path don't exist !!";
    }
}