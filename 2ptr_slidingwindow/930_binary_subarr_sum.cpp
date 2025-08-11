#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return numSubarraysWithLessSum(nums, goal) - numSubarraysWithLessSum(nums, goal - 1);
    }

private:
    int numSubarraysWithLessSum(vector<int>& nums, int goal)
    {
        if (goal < 0) return 0;
        int l = 0;
        int count = 0;
        int sum = 0;
        int n = nums.size();

        for (int r = 0; r < n; ++r)
        {
            sum += nums[r];
            while (sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
};
