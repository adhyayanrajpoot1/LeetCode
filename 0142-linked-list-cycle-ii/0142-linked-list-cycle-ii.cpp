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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL)return NULL;
        ListNode*fast = head;
        ListNode*slow = head;
        do{
            fast = fast->next->next;
            slow = slow->next;
        }
        while(fast && fast->next && fast!=slow);
        fast = head;
        while(fast && slow &&fast!=slow)
        {
            fast=fast->next;
            slow = slow->next;
        }
        if(slow==fast)return fast;
        return NULL;
    }
};