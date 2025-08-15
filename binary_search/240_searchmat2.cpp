#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            int start = 0;
            int end = matrix[0].size() - 1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (matrix[i][mid] == target)
                {
                    return true;
                }
                else if (matrix[i][mid] < target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};