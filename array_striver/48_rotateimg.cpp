#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto& row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};



/*
Example usage:
[ [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9] ]


step 1 : first transpose the matrix
[ [1, 4, 7],
  [2, 5, 8],
  [3, 6, 9] ]

step 2 : then reverse each row
[ [7, 4, 1],
  [8, 5, 2],
  [9, 6, 3] ]
*/

