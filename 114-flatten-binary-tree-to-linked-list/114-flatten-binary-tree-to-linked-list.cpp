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
    TreeNode*temp=NULL;
    void f(TreeNode*root)
    {
        if(root==NULL)return;
        f(root->right);
        f(root->left);
        root->right = temp;
        root->left = NULL;
        temp = root;
        
       
        
        
    }
    void flatten(TreeNode* root) {
        f(root);
    }
};