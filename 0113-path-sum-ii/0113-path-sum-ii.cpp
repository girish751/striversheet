class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == NULL)
            return;

        
        path.push_back(root->val);
        targetSum -= root->val;

       
        if (root->left == NULL && root->right == NULL && targetSum == 0) {
            result.push_back(path);
        }

        
        dfs(root->left, targetSum, path);
        dfs(root->right, targetSum, path);

       
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};