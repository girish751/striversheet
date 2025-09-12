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
    int length(ListNode*&head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*head1=head;
        int count= length(head);
        int x=count/2;
        int y=0;
        while(y<x){
            head1=head1->next;
            y++;
        }
        return head1;
        
    }
};
