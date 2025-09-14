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
    void reverse_given(vector<int>&input,int k,int i,vector<int>&ans){
       if(i+k<=input.size()){
        vector<int>op;
        for(int j=i;j<i+k;j++){
            op.push_back(input[j]);
        }
        reverse(op.begin(),op.end());
        for (int val : op) ans.push_back(val);
      
          return reverse_given(input,k,i+k,ans);
       }
       else{
       for (int j = i; j < input.size(); j++) {
                ans.push_back(input[j]);
            }
       }
      
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> input;
        while(head!=NULL){
            input.push_back(head->val);
            head=head->next;
        }
        int i=0;
       vector<int>ans;
        

        reverse_given(input,k,i,ans);

        ListNode*dummy=new ListNode();
        ListNode*temp=dummy;
        for(int i=0;i<ans.size();i++){
            temp->next=new ListNode(ans[i]);
            temp=temp->next;
        }
        return dummy->next;

   
        
    }
};