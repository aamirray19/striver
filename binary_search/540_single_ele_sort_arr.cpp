#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binary_search(vector<int>& arr)
    {
        int start = 0;
        int end = arr.size()-1;
        int n = arr.size();

        while (start <= end)
        {
            int mid = start + (end-start)/2;

            //edge cases
            if (n == 1) return arr[0];
            if (arr[0] != arr[1]) return arr[0];
            if (arr[n-1] != arr[n-2]) return arr[n-1];

            //main cases
            if (arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1])
            {
                return arr[mid];
            }
            if ((mid % 2 == 1 && arr[mid] == arr[mid-1]) 
            || (mid % 2 == 0 && arr[mid] == arr[mid+1]))
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

    int singleNonDuplicate(vector<int>& nums) 
    {
       return binary_search(nums); 
    }
};