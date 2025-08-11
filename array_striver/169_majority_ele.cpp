#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        int majorityElement = nums[0];
        int maxFreq = 0;

        for (int i = 0; i < n; i++) 
        {
            freqMap[nums[i]]++;
            if (freqMap[nums[i]] > maxFreq) 
            {
                maxFreq = freqMap[nums[i]];
                majorityElement = nums[i];
            }
        }

        return majorityElement;
    }
};