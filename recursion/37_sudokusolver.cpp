#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool correctfill(int row, int col, vector<vector<char>>& board, char digit)
    {
        //for checking each row has a unique number
        for (int c = 0; c < 9; c++)
        {
            if (board[row][c] == digit) return false;
        }

        //for checking each col has a unique number
        for (int r = 0; r < 9; r++)
        {
            if (board[r][col] == digit) return false;
        }

        //for checking each subgrid
        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[startrow + i][startcol + j] == digit) return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char digit = '1'; digit <= '9'; digit++)
                    {
                        if (correctfill(row, col, board, digit))
                        {
                            board[row][col] = digit;

                            if (helper(board)) return true;
                            board[row][col] = '.';  //backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        helper(board);
    }
};