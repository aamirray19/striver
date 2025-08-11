#include <bits/stdc++.h>
using namespace std;


//BRUTE FORCE

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        int cnt = 0; // Step 1: Initialize a counter
        ListNode* temp = head; // Temporary pointer to traverse the list
        
        // First loop to count the total number of nodes
        while (temp != NULL)
        {
            cnt++;          // Increment the counter
            temp = temp->next; // Move to the next node
            // Dry Run:
            // Iteration 1: temp->val = 1, cnt = 1
            // Iteration 2: temp->val = 2, cnt = 2
            // Iteration 3: temp->val = 3, cnt = 3
            // Iteration 4: temp->val = 4, cnt = 4
            // Iteration 5: temp->val = 5, cnt = 5
            // End: temp = NULL, cnt = 5
        }

        // Reset temp to head for second traversal
        temp = head; 
        int midIndex = cnt / 2; // Calculate the zero-based index of the middle node
        // For cnt = 5, midIndex = 5 / 2 = 2

        // Second loop to find the middle node
        while (midIndex > 0) 
        {
            temp = temp->next; // Move to the next node
            midIndex--;        // Decrement midIndex
            // Dry Run:
            // Iteration 1: temp->val = 1, midIndex = 2 -> temp points to 2
            // Iteration 2: temp->val = 2, midIndex = 1 -> temp points to 3
            // Iteration 3: temp->val = 3, midIndex = 0 -> Stop loop
        }

        return temp; // temp now points to the middle node
        // Output: temp->val = 3, which is the middle node
    }
};


//fast and slow pointer

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slowptr = head;
        ListNode* fastptr = head;

        while(fastptr != nullptr && fastptr->next != nullptr)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return slowptr;
    }
};