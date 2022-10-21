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
    
    int maxi = INT_MIN;
    int inorder(TreeNode*root)
    {
        if(root==NULL)return 0;
        int l = max(0,inorder(root->left));
        int r = max(0,inorder(root->right));
        int sum = root->val+l+r;
        maxi = max(maxi,sum);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        inorder(root);
        return maxi;
    }
};