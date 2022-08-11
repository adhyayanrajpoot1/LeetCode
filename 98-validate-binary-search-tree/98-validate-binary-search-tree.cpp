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
    bool f(TreeNode*root , TreeNode*min , TreeNode*max)
    {
        if(root==NULL)return true;
        if((min==NULL || root->val >min->val) && (max==NULL || root->val<max->val))
        {
            return f(root->right , root , max) && f(root->left , min , root);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return f(root , NULL , NULL);
    }
};