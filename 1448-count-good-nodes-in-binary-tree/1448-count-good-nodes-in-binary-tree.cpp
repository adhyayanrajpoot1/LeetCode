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
    
    int f(TreeNode*root , int maxi )
    {
        if(root==NULL)return 0;
        int count =0 ;
        if(root->val >= maxi)
        {
            maxi = root->val;
            count+=1;
            
        }
        return count+= (f(root->left,maxi)+f(root->right,maxi));
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        if(root->left == NULL && root->right==NULL)return 1;
        int goodNode = 1;
        goodNode+=f(root->left,root->val);
        goodNode+=f(root->right,root->val);
        return goodNode;
    }
};