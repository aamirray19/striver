#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binary_search(vector<int>& arr)
    {
        int start = 0;
        int end = arr.size()-1;
        int ans = INT_MAX;

        while (start <= end)
        {
            int mid = start + (end-start)/2;
            if (arr[start] <= arr[mid])
            {
                ans = min(ans, arr[start]);
                start = mid+1;
            }
            else
            {
                ans = min(ans, arr[mid]);
                end = mid-1;
            }
        }
        return ans;
    }

    int findMin(vector<int>& nums) 
    {
        return binary_search(nums);
    }
};