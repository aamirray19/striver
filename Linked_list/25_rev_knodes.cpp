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

    // reverse nodes from head until (but not including) tail
    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != tail)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev; // new head after reversal
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        // Step 1: Move pointer k steps ahead
        ListNode* tail = head;
        for (int i = 0; i < k; ++i) {
            if (!tail) return head; // not enough nodes left
            tail = tail->next;
        }

        // Step 2: Reverse first k nodes
        ListNode* newHead = reverse(head, tail);

        // Step 3: Connect reversed part with recursion result
        head->next = reverseKGroup(tail, k);

        return newHead;
    }
};
