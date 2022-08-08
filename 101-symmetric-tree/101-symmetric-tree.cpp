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
    bool f(TreeNode*l , TreeNode*r)
    {
        if(l==NULL&& r==NULL)return true;
        if(l==NULL || r==NULL)return false;
        if(l->val ==r->val && f(l->left,r->right) && f(r->left , l->right))
        {
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return f(root->left, root->right);
    }
};