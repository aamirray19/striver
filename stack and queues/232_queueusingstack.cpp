#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    public:
        stack<int> st; // Stack to simulate the queue
    
        MyQueue() {}
    
        // Push element to the back of the queue
        void push(int x) {
            st.push(x); // Stack push is O(1)
        }
    
        // Pop the element from the front of the queue
        int pop() {
            if (st.empty()) return -1; // Handle underflow if queue is empty
    
            int x = st.top(); // Get the top element (last pushed)
            st.pop();         // Remove the top element
    
            if (st.empty()) {
                // If this was the only element, it's the front of the queue
                return x;
            }
    
            // Recursive call to reach the bottom of the stack (front of the queue)
            int res = pop();
    
            // Rebuild the stack by pushing elements back
            st.push(x);
    
            return res; // Return the bottom element
        }
    
        // Get the front element of the queue without removing it
        int peek() {
            if (st.empty()) return -1;
    
            int x = st.top();
            st.pop();
    
            if (st.empty()) {
                // This is the front of the queue
                st.push(x); // Push it back since we're not removing
                return x;
            }
    
            int res = peek(); // Recurse to find the front
            st.push(x);       // Rebuild the stack
            return res;
        }
    
        // Check if the queue is empty
        bool empty() {
            return st.empty();
        }
    };
    