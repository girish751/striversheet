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
    void solve(TreeNode* root,  vector<TreeNode*>&vec)
    {
        if(!root) return ;
        solve(root->left,vec);
        vec.push_back(root);
        solve(root->right,vec);
        
    }

    TreeNode* formBST(int l, int r, vector<TreeNode*>&vec )
    {
        if(l>r) 
            return NULL;

        int mid= l+(r-l)/2;
        cout<<"mid:"<<vec[mid]->val<<"\n";
        TreeNode* root= new TreeNode(vec[mid]->val);
        root->left=formBST(l,mid-1,vec);
        root->right=formBST(mid+1, r, vec);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vec;
         solve(root,vec);
        for(int i=0;i<vec.size();i++)
        {
            cout<< vec[i]->val<<" ";
        }
        return formBST( 0,vec.size()-1,vec);
    }
};