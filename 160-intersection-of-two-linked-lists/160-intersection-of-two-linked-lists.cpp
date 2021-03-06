/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a = headA,*b=headB;
        while(headA!=headB)
        {
            headA = headA==NULL ? b : headA->next;
            headB = headB==NULL ? a : headB->next;
        }
        return headA;
    }
};