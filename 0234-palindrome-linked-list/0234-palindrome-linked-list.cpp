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
    bool isPalindrome(ListNode* head) {
        ListNode*head1=new ListNode(head->val);
        ListNode*temp=head->next;
        while(temp!=NULL){
            ListNode*xy=new ListNode(temp->val);
            xy->next=head1;
            head1=xy;
            temp=temp->next;
        }
        while(head1!=NULL && head!=NULL){
            if(head1->val!=head->val){
                return false;
            }
            else{
                head1=head1->next;
                head=head->next;
            }
        }
        return true;

        
    }
};