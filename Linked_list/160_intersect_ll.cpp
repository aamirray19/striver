#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode*t1 = headA;
        ListNode*t2 = headB;

        while(t1 && t2)
        {
            if(t1==t2)return t1;
            t1 = t1->next;
            t2 = t2->next;
            if(t1==nullptr)t1 = headB;
            else if(t2==nullptr)t2 = headA;
        }
        return nullptr;
    }
};