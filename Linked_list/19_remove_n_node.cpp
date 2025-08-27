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

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        head = reverse(head);

        if (n == 1)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            ListNode* curr = head;
            ListNode* prev = NULL;

            int cnt = 1;
            while (cnt < n)
            {
                prev = curr;
                curr = curr->next;
                cnt++;
            }

            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        return reverse(head);
    }
};