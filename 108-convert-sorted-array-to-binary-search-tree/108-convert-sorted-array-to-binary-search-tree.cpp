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
    TreeNode* f( int l ,int  r,vector<int>& nums)
    {
        if(l>r)return NULL;
        int mid = (l+r)/2;
        TreeNode*root = new TreeNode(nums[mid]);
        TreeNode*child1 = f(l,mid-1,nums);
        TreeNode*child2 = f(mid+1,r,nums);
        root->left = child1;
        root->right = child2;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        return f(l,r,nums);
    }
};