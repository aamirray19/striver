#include <bits/stdc++.h>
using namespace std;
// Implementing a stack using a single queue
class MyStack {
public:
    queue<int> q;

    // Constructor
    MyStack() 
    {
        // Nothing needed here as the queue is already initialized
    }
    
    // Push element x onto stack
    void push(int x) 
    {
        int s = q.size(); // Store current size of queue
        q.push(x);        // Add new element to the back

        // Rotate the queue: move the previous elements behind the new one
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }

        /*
        Dry run for push(3), push(5), push(7):
        Initial: q = []
        push(3): q = [3]
        push(5): q = [5, 3]       <- rotate once
        push(7): q = [7, 5, 3]    <- rotate twice
        So, the newest element is always at the front, like a stack!
        */
    }
    
    // Removes the element on top of the stack and returns it
    int pop() 
    {
        if (q.empty()) return -1;     // Return -1 if stack is empty
        int val = q.front();          // The "top" is at the front of the queue
        q.pop();                      // Remove the top element
        return val;
    }
    
    // Get the top element
    int top() 
    {
        if (q.empty()) return -1;     // Return -1 if stack is empty
        return q.front();             // Return the element at the front
    }
    
    // Returns whether the stack is empty
    bool empty() 
    {
        return q.empty();             // Check if the queue is empty
    }
};

/**
 * Usage Example:
int main() {
    MyStack* obj = new MyStack();
    obj->push(10);  // Stack: [10]
    obj->push(20);  // Stack: [20, 10]
    obj->push(30);  // Stack: [30, 20, 10]

    cout << obj->top() << endl;    // Output: 30
    cout << obj->pop() << endl;    // Output: 30, Stack: [20, 10]
    cout << obj->top() << endl;    // Output: 20
    cout << obj->empty() << endl;  // Output: 0 (false)

    return 0;
}
 */
