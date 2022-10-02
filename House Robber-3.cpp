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
    pair<int,int> fun(TreeNode* root)// in the pair first gives the max when root is included and second gives ans when root is not included
    {
        if(root==NULL)
            return {0,0};
        pair<int,int> res;
        pair<int,int> lr=fun(root->left);
        pair<int,int> rr=fun(root->right);
        res.first=root->val+lr.second+rr.second;
        res.second=max(lr.first,lr.second)+max(rr.first,rr.second);
        return res;
    }
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        pair<int,int> ans=fun(root);
        return max(ans.first,ans.second);
    }
};
