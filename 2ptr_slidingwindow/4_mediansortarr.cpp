#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> merged;

        while (l < m && r < n) 
        {
            if (nums1[l] < nums2[r]) 
            {
                merged.push_back(nums1[l++]);
            } 
            else 
            {
                merged.push_back(nums2[r++]);
            }
        }

        while (l < m) merged.push_back(nums1[l++]);
        while (r < n) merged.push_back(nums2[r++]);

        int merge_size = merged.size();
        int mid = merge_size / 2;

        if (merge_size % 2 != 0) 
        {
            return merged[mid];  
        } 
        else 
        {
            return (merged[mid - 1] + merged[mid]) / 2.0; 
        }
    }
};