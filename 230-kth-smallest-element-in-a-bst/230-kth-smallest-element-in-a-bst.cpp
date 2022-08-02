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
    void dfs(TreeNode*root , int &k , int&num)
    {
        if(root==NULL)return;
        dfs(root->left,k, num);
        k--;
        if(k==0){
            num = root->val;
            return;
        }
        dfs(root->right,k,num);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int num =0;
        dfs(root,k,num);
        return num;
    }
};