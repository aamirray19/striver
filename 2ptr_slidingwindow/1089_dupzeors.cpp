#include <bits/stdc++.h>
using namespace std;


//brute force solution
class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                ans.push_back(arr[i]);
                ans.push_back(0);
            }
            else
            {
                ans.push_back(arr[i]);
            }
            arr[i] = ans[i];
        }  
    }
};


//2ptr solution
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int l = 0, r = arr.size();

        while (l < r) 
        {
            if (arr[l] == 0) 
            {
                arr.insert(arr.begin() + l, 0); // Insert 0 at index l
                l = l + 2; // Skip the duplicated zero and the original zero
                arr.pop_back(); // Remove the last element to maintain the original size
            } 
            else 
            {
                l++;
            }
        }
    }
};