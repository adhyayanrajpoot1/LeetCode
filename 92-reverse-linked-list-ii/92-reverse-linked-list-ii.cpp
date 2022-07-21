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
    void reverse(ListNode*s , ListNode*e)
    {
        ListNode*prev=NULL;
        ListNode*curr = s;
        ListNode*n=s->next;
        while(prev!=e)
        {
            curr->next = prev;
            prev=curr;
            curr=n;
            if(n!=NULL)n=n->next;
            
        }
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int l = left-1;
        int r = right;
        
        ListNode*dummy = new ListNode(-1);
        ListNode*ans = dummy;
        dummy->next = head;
        ListNode*temp = dummy;
        ListNode*s=NULL;
        ListNode*e=NULL;
        while(temp!=NULL && (l ||r))
        {
            if(l==0)s=temp;
            if(r==0)e=temp;
            temp=temp->next;
            l--;
            r--;
        }
        ListNode*temp1 = s->next;
        ListNode*temp2 = e->next;
        reverse(s->next,e);
        s->next = e;
        
        temp1->next = temp2;
        return ans->next;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};