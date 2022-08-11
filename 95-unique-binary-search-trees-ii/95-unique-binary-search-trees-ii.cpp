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
    vector<TreeNode*> helper(int s , int e) {
        if(s>e){
            vector<TreeNode*>ans;
            ans.push_back(NULL);
            return ans;
        }
        vector<TreeNode*>ans;
        for(int i = s ; i <= e ; i++)
        {
            vector<TreeNode*>l = helper(s,i-1);
            vector<TreeNode*>r = helper(i+1,e);
            for(auto a : l )
            {
                for(auto b : r)
                {
                    TreeNode*root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    ans.push_back(root);
                }
            }
        }
        return ans;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};