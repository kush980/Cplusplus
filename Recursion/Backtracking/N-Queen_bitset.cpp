#include<iostream>
#include<bitset>
using namespace std;


//creating bitset to reduce time complexity
bitset<30> col,d1,d2;

void solve(int r,int n,int &ans)
{
    //base case
    if(r==n)
    {
        ans++;
        return;
    }
    //recursive case
    for(int c=0;c<n;c++)
    {
        //col[c] represents that no queen is present in column C
        //r+c = row column gives us all the right-hand side diagonals
        //r-c+n-1 gives us all the left handed side diagonals 
        //all these are stored in bitset so that we dont have to run one more and can be check from the bitset array itself whether the queen is present over thee or not
        //this reduces time complexity
        if(!col[c]&& !d1[r+c]&& !d2[r-c+n-1])
        {
            col[c]=d1[r+c]=d2[r-c+n-1]=1;
            solve(r+1,n,ans);
            col[c]=d1[r+c]=d2[r-c+n-1]=0;
        }
    }
}


int main()
{
    int n;
    cin>>n;
    // int board[20][20];
    int ans=0;
    solve(0,n,ans);
    cout<<ans<<endl;
}