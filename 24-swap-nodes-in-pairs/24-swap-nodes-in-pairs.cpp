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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        ListNode*temp = head;
        ListNode*ans=NULL;
        if(temp!=NULL && temp->next!=NULL)
        {
            ListNode*rev = temp->next;
            ans=rev;
            temp->next=rev->next;
            rev->next = temp;
        }
        head->next = swapPairs(head->next);
        return ans;
    }
};