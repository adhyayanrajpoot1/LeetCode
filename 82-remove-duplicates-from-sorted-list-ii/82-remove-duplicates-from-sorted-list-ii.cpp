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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *prev=dummy;
        while(head!=NULL){
        if(head->next!=NULL && head->val==head->next->val){
            while(head->next!=NULL && head->val==head->next->val)head=head->next;
                prev->next=head->next;
            }
        else prev=prev->next;
        head=head->next;
        }
        return dummy->next;
            
    
        // ListNode*prev = NULL;
        // while(head!=NULL)
        // {
        //     prev = head;
        //     if(head->next!=NULL && head->next->next!=NULL && head->next->val==head->next->next->val)
        //     {
        //         while(head->next!=NULL && head->next->next!=NULL && head->next->val==head->next->next->val)
        //         {
        //             head=head->next->next;
        //         }
        //         head=head->next;
        //         prev->next = head;
        //     }
        //     else head=head->next;
        // }
        // return head;
    }
};