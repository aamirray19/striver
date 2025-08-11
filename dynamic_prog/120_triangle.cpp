#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        int n = triangle.size();
        if (row == n - 1) return triangle[n-1][col];
        if (dp[row][col] != -1) return dp[row][col];

        int down = triangle[row][col] + helper(row + 1, col, triangle, dp);
        int diag = triangle[row][col] + helper(row + 1, col + 1, triangle, dp);

        return dp[row][col] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, 0, triangle, dp);
    }
};