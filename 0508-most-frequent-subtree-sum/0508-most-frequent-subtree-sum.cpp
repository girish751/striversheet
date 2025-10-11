class Solution {
public:
    int mp=0;// store the max frequency
    unordered_map<int,int> m;// val -> frequency
    vector<int> findFrequentTreeSum(TreeNode* root) {
        fun(root);
        vector<int> res;
        for(auto x:m)
        {
            if(x.second==mp)// val -> freq == max freq
                res.push_back(x.first);
        }
        return res;
    }
    int fun(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        // subtree sum
        int t=root->val;
        t+=fun(root->left);
        t+=fun(root->right);
        
        m[t]++;
        mp=max(mp,m[t]);// update max frequency
        return t;
    }
};