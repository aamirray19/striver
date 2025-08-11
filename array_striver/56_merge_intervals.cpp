#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;

        // Step 1: Sort based on start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Start with the first interval
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) 
        {
            // Get the last added interval in ans
            vector<int>& last = ans.back();

            // If intervals overlap, merge them
            if (intervals[i][0] <= last[1]) 
            {
                last[1] = max(last[1], intervals[i][1]);
            } 
            else 
            {
                // No overlap, add the interval as is
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
