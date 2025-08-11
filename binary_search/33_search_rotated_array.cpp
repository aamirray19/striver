#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binary_search(vector<int>& arr, int key)
    {
        int start = 0;
        int end = arr.size()-1;

        while (start <= end)
        {
            int mid = start + (end-start)/2;
            if (arr[mid] == key)
            {
                return key;
                while (arr[mid] < arr[mid+1])
                {
                    mid++;
                }
                start = mid;
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
        return -1;
    }

    int search(vector<int>& nums, int target) 
    {
        return binary_search(nums, target);   
    }
};