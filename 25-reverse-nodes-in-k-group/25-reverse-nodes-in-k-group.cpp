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
    void reverse(ListNode*head,ListNode*e)
    {
        ListNode*c=head,*p=NULL,*n=head->next;
        
        while(p!=e)
        {
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL)n=n->next;
            
        }
    }
    // void reverse(ListNode*s , ListNode*e)
    // {
    //     if(s==NULL)return;
    //     ListNode*p = NULL;
    //     ListNode*c = s;
    //     ListNode*n = s->next;
    //     while(c!=e)
    //     {
    //         c->next = p;
    //         p=c;
    //         c=n;
    //         if(n!=NULL)n=n->next;
    //     }
    // }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num = k;
        if( head==NULL || head->next==NULL||k==1)return head;
        ListNode*s = head;
        ListNode*e = head;
        k=k-1;
        while(k--)
        {
            e=e->next;
            if(e==NULL)return head;
        }
        
        
        
        ListNode*newNode = reverseKGroup(e->next,num);
        reverse(s,e);
        s->next = newNode;
        return e;
    }
};