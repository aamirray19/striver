#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) 
    {
        int ele_sum = 0;
        int dig_sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            ele_sum = ele_sum + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != 0) {
                dig_sum = dig_sum + nums[i] % 10;
                nums[i] = nums[i] / 10;
            }
        }
        return abs(ele_sum - dig_sum);
    }
};