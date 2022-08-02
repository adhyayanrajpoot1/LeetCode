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
    ListNode*reverse(ListNode*head){
        ListNode*c = head,*p = NULL , *n = head->next;
        while(c!=NULL)
        {
            c->next = p;
            p=c;
            c=n;
            if(n!=NULL)n=n->next;
        }
        return p;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)return;
        ListNode*fast=head,*slow = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*rv = reverse(slow->next);
        slow->next=NULL;
        // while(rv!=NULL)
        // {
        //     cout<<rv->val<< ' ';
        //     rv=rv->next;
        // }
        // return;
       //ListNode*prev1;*prev2;
        ListNode*head2=head;
        if(head!=NULL)
        head=head->next;
        while(head!=NULL && rv!=NULL)
        {
            ListNode*temp1,*temp2;
            temp1 = head->next;
            temp2 = rv->next;
            head2->next = rv;
            head2=rv;
            head2->next = head;
            head2=head;
            head=temp1;
            rv=temp2;
        }
        if(head!=NULL){
            head2->next = head;
        }
        if(rv!=NULL)
        {
            rv->next = rv;
        }
        head=head2;
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};