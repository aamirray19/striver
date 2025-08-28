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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode dummy;
        ListNode* curr = &dummy;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1-> val < l2->val)
            {
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        while (l1 != NULL)
        {
            curr->next = new ListNode(l1->val);
            l1 = l1->next;
            curr = curr->next;
        }

        while (l2 != NULL)
        {
            curr->next = new ListNode(l2->val);
            l2 = l2->next;
            curr = curr->next;
        }
        return dummy.next;
    }
};