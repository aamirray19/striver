#include <bits/stdc++.h>
using namespace std;    

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next) return head;  // handle empty or 1-node list

        // Step 1: Count length properly
        int cnt = 1;
        ListNode* tail = head;  // keep a pointer to the last node

        while (tail->next != nullptr) {
            cnt++;
            tail = tail->next;
        }

        // Step 2: Effective rotations
        int rotate = k % cnt;
        if (rotate == 0) return head;

        // Step 3: Find the cut point
        ListNode* curr = head;
        for (int i = 0; i < cnt - rotate - 1; i++) {
            curr = curr->next;
        }

        // Step 4: Cut and reconnect
        ListNode* newnode = curr->next; // new head
        curr->next = nullptr;           // break
        tail->next = head;              // attach tail to old head

        return newnode;
    }
};