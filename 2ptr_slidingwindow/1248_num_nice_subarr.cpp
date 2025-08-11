#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int l = 0;
        int r = 0;
        int count = 0; //keeps cnt of the total odd numbers
        int maxlen = 0; //keeps cnt of the total subarrays
        int result = 0;
        int n = nums.size();

        while (r < n)
        {
            if (nums[r] % 2 != 0)
            {
                count++;
                maxlen = 0;
            }
            
            while (count == k)
            {
                maxlen++;
                if (nums[l] % 2 != 0)
                {
                    count--;
                }
                l++;
            }
            result += maxlen;
            r++;
        }
        return result;
    }
};