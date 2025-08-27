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
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode* fastptr = head;
        ListNode* slowptr = head;

        if (!head || !head->next) return nullptr;

        int cnt = 0;

        while (fastptr != NULL)
        {
            cnt++;
            fastptr = fastptr->next;
        }

        int pos = cnt / 2;

        for (int i = 0; i < pos - 1; i++)
        {
            slowptr = slowptr->next;
        }

        ListNode* temp = slowptr->next;
        slowptr->next = slowptr->next->next;
        delete temp;

        return head;
    }
};