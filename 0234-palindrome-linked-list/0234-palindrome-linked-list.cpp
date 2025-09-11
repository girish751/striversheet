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
        vector<int>v1;
        while(head!=NULL){
            v1.push_back(head->val);
            head=head->next;
        }
        int i=0;
        int j=v1.size()-1;
        while(i<j){
            if(v1[i]==v1[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};