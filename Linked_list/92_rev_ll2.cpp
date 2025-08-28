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

    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (!head || left == right) return head;

        ListNode* temp = head;  // to traverse the LL

        ListNode* l1 = NULL;
        ListNode* l2 = NULL;
        ListNode* l3 = NULL;
        ListNode* l4 = NULL;

        int pos = 1;  // assuming we aready have a sorted list

        while (temp != NULL)
        {
            if (pos == left - 1) l1 = temp;
            else if (pos == left) l2 = temp;
            else if (pos == right) l3 = temp;
            else if (pos == right + 1) l4 = temp;

            temp = temp->next;
            pos++;
        }

        if (!l2 || !l3) return head;  

        // cutting the links
        l3->next = NULL;

        // reversing 
        ListNode* revll = reverse(l2);

        // reconnecting the links
        if (l1) l1->next = revll;
        else head = revll;  // left = 1
        l2->next = l4; 

        return head;
    }
};