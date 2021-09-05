#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number)
{
    for(int x=0;x<n;x++)
    {
        //row and column check
        if(mat[i][x]==number || mat[x][j]==number)
        {
            return false;
        }
    }

    //each grid check 
    int rn=sqrt(n);
    int cx=(i/rn)*rn;   //coordinate of x of the grid
    int cy=(j/rn)*rn;   //coordinate of y of the grid

    for(int x=cx;x<cx+rn;x++)
    {
        for(int y=cy;y<cy+rn;y++)
        {
            if(mat[x][y]==number)
            {
                return false;
            }
        }
    }
    return true;
}

bool solvesudoku(int mat[][9],int i,int j,int n)
{
    //base case
    {
        if(i==n)
        {
            //print the elements
            for(int k=0;k<n;k++)
            {
                for(int l=0;l<n;l++)
                {
                    cout<<mat[k][l]<<" ";
                }
                cout<<endl;
            }

            return true;
        }

        //conditional case
        //when we iterate to the last element of the row
        if(j==n)
        {
           return solvesudoku(mat,i+1,0,n);
        }
        //skip the pre-filled cells
        if(mat[i][j]!=0)
        {
           return solvesudoku(mat,i,j+1,n);
        }

        //recursive case
        for(int number=1;number<=n;number++)
        {
            if(canPlace(mat,i,j,n,number))
            {
                //assumption 
                mat[i][j]=number;
                bool issolvable=solvesudoku(mat,i,j+1,n);
                if(issolvable)
                {
                    return true;
                }
            }
        }
        //if the assumption is wrong then we have to backtrack and change our assumption
        mat[i][j]=0;
        return false;
    }
}

int main()
{
    int mat[9][9]=
               {   
                  {5,3,0,0,7,0,0,0,0},
                  {6,0,0,1,9,5,0,0,0},
                  {0,9,8,0,0,0,0,6,0},
                  {8,0,0,0,6,0,0,0,3},
                  {4,0,0,8,0,3,0,0,1},
                  {7,0,0,0,2,0,0,0,6},
                  {0,6,0,0,0,0,2,8,0},
                  {0,0,0,4,1,9,0,0,5},
                  {0,0,0,0,8,0,0,7,9}
               };

    solvesudoku(mat,0,0,9);
    return 0;
}