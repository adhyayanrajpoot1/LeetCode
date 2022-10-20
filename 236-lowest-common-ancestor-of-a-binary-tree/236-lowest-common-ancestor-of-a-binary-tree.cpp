/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)return root;
        //if(root->left == p || root->right==q)return root;
        TreeNode*node1 = lowestCommonAncestor(root->left,p,q);
        TreeNode*node2= lowestCommonAncestor(root->right,p,q);
        return node1==NULL ? node2:node2==NULL ? node1 : root;
    }
};