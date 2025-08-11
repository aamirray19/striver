#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;  // Initialize pivot index
        int n = nums.size();

        // Step 1: Find the first decreasing element from the end (pivot)
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                ind = i;  // Found the pivot
                break;
            }
        }

        // If no pivot found, the array is in descending order
        // Reverse to get the first permutation (sorted ascending)
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest number > nums[ind] from the end
        for (int i = n-1; i >= ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);  // Swap with the pivot
                break;
            }
        }

        // Step 3: Reverse the suffix after the pivot to get the smallest order
        reverse(nums.begin() + ind + 1, nums.end());
    }
};

