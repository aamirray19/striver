#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool binary_search(vector<int>& arr, int key)
    {
        int start = 0;
        int end = arr.size()-1;

        while (start <= end)
        {
            int mid = start + (end-start)/2;
            if (arr[mid] == key || arr[start] == key || arr[end] == key)
            {
                return true;
            }
            if (arr[start] == arr[mid] && arr[end] == arr[mid])
            {
                start++;
                end--;
            }
            //left side sorted
            else if (arr[start] <= arr[mid])
            {
                if(arr[start] <= key && key <= arr[mid])
                {
                    end = mid-1;
                }
                else
                {
                    start = mid+1;
                }
            }
            //right side sorted
            else
            {
                if (arr[mid] <= key && key <= arr[end])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        } 
        return false;
    }
    bool search(vector<int>& nums, int target) 
    {
        return binary_search(nums, target);
    }
};