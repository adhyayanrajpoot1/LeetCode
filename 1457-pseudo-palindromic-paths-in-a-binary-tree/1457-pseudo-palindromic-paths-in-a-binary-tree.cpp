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
    //   int pseudoPalindromicPaths(TreeNode* root, int count = 0) {
    //     if (!root) return 0;
    //     count ^= 1 << (root->val - 1);
    //     int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
    //     if (root->left == root->right && (count & (count - 1)) == 0) res++;
    //     return res;
    // }
    int count=0;
    void dfs(TreeNode*root,unordered_map<int,int>&v)
    {
        if(root==NULL)return;
        v[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int odd = 0;
            for(auto it : v)
            {
                
                if(it.second%2==1){
                    odd++;
                }
            }
            if(odd<=1)count++;
            
        }
        dfs(root->left,v);
        dfs(root->right,v);
        
        v[root->val]--;
        
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        //vector<int>v(10,0);
        unordered_map<int,int>v;
        dfs(root,v);
        return count;
    }
};