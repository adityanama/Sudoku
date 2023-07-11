#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class Sudoku{
public:
    bool isSafe(int r, int c, vector<vector<char>> &board, char k)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[r][i] == k || board[i][c] == k)
                return false;

            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == k)
                return false;
        }
        return true;
    }

    bool solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isSafe(i, j, board, ch))
                        {
                            board[i][j] = ch;
                            if (solveSudoku(board) == true)
                                return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Sudoku S;
    vector<vector<char>> board(9, vector<char>(9));

    cout<<endl<<endl;

    cout<<"***************** WELCOME TO SUDOKU SOLVER *****************"<<endl<<endl;

    cout<<"Enter the inital values in sudoku row wise"<<endl;
    cout<<"( For empty cells type '.' )"<<endl<<endl;

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>board[i][j];
    
    cout<<endl<<endl<<"***************** SOLUTION OF THE GIVEN SUDOKU *****************"<<endl<<endl;

    S.solveSudoku(board);

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {    
            cout<<board[i][j]<<" ";
            if(j==2 || j==5 || j==8)
                cout<<"  ";
        }

        if(i==2 || i==5 || i==8)
            cout<<endl;
        cout<<endl;
    }
    main();
    getch();
    
    return 0;
}