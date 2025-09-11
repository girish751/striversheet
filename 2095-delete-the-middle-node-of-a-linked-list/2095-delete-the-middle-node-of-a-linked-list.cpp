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
    int leng(ListNode*&head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*xy=head;
        ListNode*temp=head;
        ListNode*ptr=NULL;
        int count=leng(head);
        if(count==1){
            return NULL;
        }
        int x=count/2;
        // if(count%2==0){
        //      x=count/2;
        // }
        // else{
        //      x=(count/2)+1;
        // }
        int y=0;
        while(y<x ){
            ptr=temp;
            temp=temp->next;
            y++;

        }
        if(temp->next==NULL){
            ptr->next=NULL;
        }
        else{
            ptr->next=temp->next;
            temp->next==NULL;
        }
        delete(temp);
        return xy;

      
       
        
        
       
       


        
    }
};