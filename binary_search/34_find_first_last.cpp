#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> binary_search(vector<int>& arr, int key)
    {
        int start = 0;
        int end = arr.size()-1;
        int l = 0, r = 0;

        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if (arr[mid] == key)
            {
                l = mid;
                r = mid;
                while (l > start && arr[l-1] == key)
                {
                    l--;
                }
                while (r < end && arr[r+1] == key)
                {
                    r++;
                }
                return {l, r};
            }
            else if (key > arr[mid])
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return {-1, -1};
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        return binary_search(nums, target);
    }
};