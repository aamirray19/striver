#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<bool> rows(r, false);
        vector<bool> columns(c, false);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = true;
                    columns[j] = true;
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (rows[i] || columns[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};