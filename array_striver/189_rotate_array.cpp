#include <bits/stdc++.h>
using namespace std;

//APPROACH 1
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k = k % nums.size(); 
        //we are doing the modulo here to find the number after multiple rotations or if the k 
        //is a multiple of size 
        int temp[k];
        for (int i = 0; i < k; i++)
        {
            temp[i] = nums[i];
        }
        // we are storing the elements in a new array 

        for (int i = k; i < nums.size(); i++)
        {
            nums[i - k] = nums[i];
        }
        //we do this as if we take i at index 3 and k = 3 then 3-3 gives 0 index thus shifting
        //each element to its new index

        for (int i = nums.size() - k; i < nums.size(); i++)
        {
            nums[i] = temp[i - (nums.size() - k)];
        }
        //now here we take temp[i - (n - k)] as lets assume i is 3 then size = 6 and k = 3 
        //thus if we subtract we will shift back 3 places to get the 0  index in temp and thus 
        //successfully placing it at nums[i]
    }
};

//APPROACH 2
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        //firstly we reverse the full array which gives us 7 6 5 4 3 2 1
        reverse(nums.begin(), nums.begin() + k);
        //then we reverse till k thus giving us 5 6 7 4 3 2 1 
        reverse(nums.begin() + k, nums.end());
        //then we will reverse the remaining part thus giving us the following 5 6 7 1 2 3 4
    }
};