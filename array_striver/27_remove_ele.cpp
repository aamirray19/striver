#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int l = 0;
        int r = nums.size();

        while (l < r)
        {
            if (nums[l] == val)
            {
                nums[l] = nums[r-1];
                r--;
            }
            else
            {
                l++;
            }
        }
        return l;
    }
};