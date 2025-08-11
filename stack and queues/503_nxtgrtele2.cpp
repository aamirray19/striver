#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) 
        {
            int n = nums.size(); // Get the size of the input array
            vector<int> ans(n, -1); // Initialize the result array with -1
            stack<int> st; // Stack to store elements for comparison
    
            // Traverse the array in reverse order twice (circular array)
            for (int i = 2 * n - 1; i >= 0; i--)
            {
                int curr = nums[i % n]; // Get the current element (circular indexing)
                
                // Remove elements from the stack that are less than or equal to the current element
                while(!st.empty() && st.top() <= curr)
                {
                    st.pop();
                }
    
                // If we are in the first pass (i < n), update the result array
                if (i < n)
                {
                    if (!st.empty()) 
                        ans[i] = st.top(); // The top of the stack is the next greater element
                    else 
                        ans[i] = -1; // No greater element found
                }
                
                // Push the current element onto the stack
                st.push(curr);
            }
            return ans; // Return the result array
        }
};

/*
Dry Run Example:
Input: nums = {1, 2, 1}

Step-by-step execution:
1. Initialization:
   - n = 3
   - ans = {-1, -1, -1}
   - st = {}

2. Outer Loop:
   - Loop runs from i = 5 to i = 0 (2 * n - 1 to 0).

Iteration 1: i = 5 (circular index 5 % 3 = 2)
   - curr = nums[2] = 1
   - Stack is empty, so no elements are popped.
   - Push curr onto the stack: st = {1}

Iteration 2: i = 4 (circular index 4 % 3 = 1)
   - curr = nums[1] = 2
   - Pop 1 from the stack because st.top() <= curr (1 <= 2).
   - Stack is now empty.
   - Push curr onto the stack: st = {2}

Iteration 3: i = 3 (circular index 3 % 3 = 0)
   - curr = nums[0] = 1
   - Stack is not empty, and st.top() > curr (2 > 1).
   - Since i < n, update ans[0] = st.top() = 2.
   - Push curr onto the stack: st = {2, 1}

Iteration 4: i = 2 (circular index 2 % 3 = 2)
   - curr = nums[2] = 1
   - Pop 1 from the stack because st.top() <= curr (1 <= 1).
   - Stack is not empty, and st.top() > curr (2 > 1).
   - Since i < n, update ans[2] = st.top() = 2.
   - Push curr onto the stack: st = {2, 1}

Iteration 5: i = 1 (circular index 1 % 3 = 1)
   - curr = nums[1] = 2
   - Pop 1 and 2 from the stack because st.top() <= curr (1 <= 2, 2 <= 2).
   - Stack is now empty.
   - Since i < n, update ans[1] = -1 (no greater element found).
   - Push curr onto the stack: st = {2}

Iteration 6: i = 0 (circular index 0 % 3 = 0)
   - curr = nums[0] = 1
   - Stack is not empty, and st.top() > curr (2 > 1).
   - Since i < n, update ans[0] = st.top() = 2.
   - Push curr onto the stack: st = {2, 1}

Final Result:
- ans = {2, -1, 2}
*/