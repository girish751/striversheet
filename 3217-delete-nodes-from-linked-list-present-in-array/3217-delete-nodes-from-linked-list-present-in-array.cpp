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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
//insert all values to set

        for(int val:nums)s.insert(val);
        ListNode* p = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* q = dummy;
//iterate over head using p pointer

        while(p){
            if(!s.count(p->val)){
// if val is unique then add it to  dummy node

                 q->next = new ListNode(p->val);
                 q = q->next;
            }
            p = p->next;
        }
        return dummy->next;
    }
};