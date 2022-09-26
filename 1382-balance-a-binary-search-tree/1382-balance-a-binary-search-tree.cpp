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
    void inorder(TreeNode*root , vector<int>&v)
    {
        if(root==NULL)return ;
        if(root->left)inorder(root->left,v);
        v.push_back(root->val);
        if(root->right)inorder(root->right,v);
    }
    TreeNode*f(TreeNode*root , vector<int>&v , int s , int e)
    {
        if(root==NULL)return NULL;
        if(s>e)return NULL;
        int mid = (s+e)/2;
        TreeNode*temp = new TreeNode(v[mid]);
        temp ->left = f(temp,v,s,mid-1);
        temp->right = f(temp,v,mid+1,e);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int mid = (0+v.size()-1)/2;
        TreeNode*ans=new TreeNode(v[mid]);
        ans->left = f(ans , v , 0 , mid-1);
        ans->right = f(ans , v , mid+1,v.size()-1);
        return ans;
    }
};