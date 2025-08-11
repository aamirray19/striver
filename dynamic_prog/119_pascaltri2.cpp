#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> prevrow;

        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> curr_row(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                curr_row[j] = prevrow[j-1] + prevrow[j];
            }
            prevrow = curr_row;
        }
        return prevrow;
    }
};