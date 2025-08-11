#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> pos;
        vector<int> neg;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }

        vector<int> res;
        int p = 0;
        int n = 0;
        while((p < pos.size()) &&  (n < neg.size()))
        {
            res.push_back(pos[p]);
            p++;
            res.push_back(neg[n]);
            n++;
        } 
        return res;
    }
};