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
    vector<vector<int>>ans;
    void dfs(TreeNode*root , int tar , int sum,vector<int>&ds)
    {
        if(root==NULL){
            
            return;
        }
        ds.push_back(root->val);
        sum+=root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==tar)ans.push_back(ds);
        }
        else{
            if(root->left)
            {
                dfs(root->left ,tar,sum ,ds);
            }
            if(root->right)
            {
                dfs(root->right,tar,sum,ds); 
            }
           
        }
         ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return {};
        int sum = 0;
        vector<int>ds;
        //ds.push_back(root->val);
        dfs(root,targetSum,sum,ds);
        return ans;
    }
};