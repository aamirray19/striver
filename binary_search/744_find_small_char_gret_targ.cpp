#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char binary_search(vector<char>& arr, char target) {
        int start = 0;
        int end = arr.size() - 1;
        char ans = arr[0]; // Default answer is the first element (for circular behavior)

        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (arr[mid] > target) {
                ans = arr[mid]; // Update the answer if mid element is greater than target
                end = mid - 1;  // Narrow the search range to the left half
            } else {
                start = mid + 1; // Narrow the search range to the right half
            }
        }

        return ans;
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        return binary_search(letters, target);
    }
};