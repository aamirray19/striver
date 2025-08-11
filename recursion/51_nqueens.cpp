#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Check if it's safe to place a queen at board[row][col]
    bool issafe(int row, int col, vector<string>& board, int n)
    {
        // Check upper-left diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q') return false;
        }

        // Check left side of the current row
        for (int j = col; j >= 0; j--) {
            if (board[row][j] == 'Q') return false;
        }

        // Check lower-left diagonal
        for (int r = row, c = col; r < n && c >= 0; r++, c--) {
            if (board[r][c] == 'Q') return false;
        }

        return true; // Safe to place the queen
    }

    // Recursive function to solve the N-Queens problem
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n)
    {
        if (col == n) {
            ans.push_back(board);  // Found a valid configuration
            return;
        }

        for (int row = 0; row < n; row++) {
            if (issafe(row, col, board, n)) {
                board[row][col] = 'Q';        // Place queen
                solve(col + 1, board, ans, n); // Move to next column
                board[row][col] = '.';        // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        // Initialize the board with dots
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(0, board, ans, n);  // Start solving from column 0
        return ans;
    }
};
