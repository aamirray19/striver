#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int xor_arr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xor_arr = xor_arr ^ nums[i];
        }
        return xor_arr;   
    }
};