#include<iostream>
using namespace std;

bool issafe(int board[][10],int i,int j,int n)
{
    //you can check for columns
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    int x=i;
    int y=j;

    //you can check for the left diagonal 
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }

    //you can check for the right diagonal 
    x=i;
    y=j;
    while(x>=0 && y<=n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    //this position is now safe
    return true;
}


bool solveNQueen(int board[][10],int i,int n)
{
    //base case
    if(i==n)
    {
        //you have succesfully place the queen in the rows(0....n)
        //print the board

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"Q";
                }
                else
                {
                    cout<<" _ ";
                }
                
            }
            cout<<endl;
        }
        cout<<endl;
        //return true;        //by returning true we will stop the program when we get the first result .
        return false;          //if we return false the program will never know we got the result or not and will print all the possibilies of placing the queen ;
    }
    //recursive case
    //try to place the queen in current row and cell one the remaining part too which will be solved bt=y recursion-backtracking
    for(int j=0;j<n;j++)
    {
        //i have to check whether the position i,j is safe is or not
        if(issafe(board,i,j,n))
        {
            //place the queen  - by placing u r assuming the position at which u placed the w=queen first is right
            board[i][j]=1;
            
            bool next = solveNQueen(board,i+1,n);
            if(next)
            {
                return true;
            }

            //if the assumption is wrong then we have to backtrack 
            board[i][j]=0;

        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;

    int board[10][10];
    solveNQueen(board,0,n);
}