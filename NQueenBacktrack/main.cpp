#include <iostream>

using namespace std;

bool issafe(int board[][10], int i, int j, int n)
{
    //checking vertically
    for (int row=0;row<i;row++)
    {
        if(board[row][j]==1)
            return false;
    }

    //check right diagonal
    int y=i;
    int x=j;
    while(x<n&&y>=0)
    {
        if(board[y][x]==1) return false;
        x++;
        y--;
    }

    //check left diagonal
    y=i;
    x=j;
    while(x>=0&&y>=0)
    {
        if(board[y][x]==1) return false;
        x--;
        y--;
    }
    return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
    if (i==n)
    {
        //Print the board
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (board[i][j]==1)
                {
                    cout<<"Q ";
                }
                else cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return false;
    }
    //Recursive case
    else
    {
        for (int j=0;j<n;j++)
        {
            if(issafe(board,i,j,n))
            {
                board[i][j]=1;
                int rakhpayenext = solveNQueen(board, i+1, n);
                if(rakhpayenext)
                {
                    return true;
                }
                else
                {
                    board[i][j]=0;
                }
            }
        }
        return false;
    }

}

int main()
{
    int n;
    cin>>n;
    int board[10][10] = {0};
    solveNQueen(board, 0, n);
    return 0;
}
