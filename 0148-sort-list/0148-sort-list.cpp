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
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode*dummy=new ListNode();
        ListNode*temp=dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
    if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return dummy->next;
    }
    ListNode* middle(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode*mid=middle(head);
        ListNode*right=mid->next;
        mid->next=NULL;
        ListNode*left=head;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
       
        
    }
};