#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int arr_diff = INT_MAX;
        int diff = 0;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            diff = arr[i+1] - arr[i];
            arr_diff = min(arr_diff, diff);
        }
        int min_diff = arr_diff;
        vector<vector<int>> result;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i+1] - arr[i] == min_diff)
            {
                result.push_back({arr[i], arr[i+1]});
            }
        } 
        return result; 
    }
};