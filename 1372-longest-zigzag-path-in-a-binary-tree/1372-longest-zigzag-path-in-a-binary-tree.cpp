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
public:
    int ans = 0;
    void solve(TreeNode* root, int i, bool isLeft) {
        if(!root) return;
        ans = max(ans, i);
        if(isLeft) {
            solve(root->right, 1, true);
            solve(root->left, i+1, false);
        } else {
            solve(root->left, 1, false);
            solve(root->right, i+1, true);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        solve(root->left, 1, false);
        solve(root->right, 1, true);
        return ans;
    }
};