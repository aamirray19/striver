#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binary_search(vector<int>& arr, int k)
    {
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;  

            if (arr[mid] == k)
            {
                return mid;
            }
            else if (k > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;  
    }

    int search(vector<int>& nums, int target) 
    {
        return binary_search(nums, target); 
    }
};
