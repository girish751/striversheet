/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int,int> travel(TreeNode* root){
        if(root==nullptr) return {0,0};
        pair<int,int> left=travel(root->left),right=travel(root->right);
        int rob=root->val+left.second+right.second;
        int not_rob=max(left.first,left.second)+max(right.first,right.second);
        return {rob,not_rob};
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> res=travel(root);
        return max(res.first,res.second);
    }
};