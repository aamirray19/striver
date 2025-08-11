#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        // Base case: last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // Bottom-up DP from second-last row to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + dp[i + 1][j];

                int diag_right = INT_MAX;
                if (j < n - 1) diag_right = matrix[i][j] + dp[i + 1][j + 1];

                int diag_left = INT_MAX;
                if (j > 0) diag_left = matrix[i][j] + dp[i + 1][j - 1];

                dp[i][j] = min({down, diag_left, diag_right});
            }
        }

        // Minimum in the top row
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
