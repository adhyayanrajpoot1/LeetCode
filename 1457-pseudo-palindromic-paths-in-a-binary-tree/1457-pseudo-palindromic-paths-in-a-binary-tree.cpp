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
      int pseudoPalindromicPaths(TreeNode* root, int count = 0) {
        if (!root) return 0;
        count ^= 1 << (root->val - 1);
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }
//     int count=0;
//     void dfs(TreeNode*root,vector<int>&v)
//     {
//         if(root==NULL)return;
        
//         if(root->left==NULL && root->right==NULL)
//         {
//             bool odd = false;
//             for(int i = 1 ; i < 10 ; i++)
//             {
                
//                 if(v[i]%2==1 && v[i]==1){
//                     if(odd)return;
//                     else
//                     {
//                         odd = true;
//                     }
//                 }
//             }
//             if(odd)count++;
//         }
//         v[root->left->val]++;
//         dfs(root->left,v);
//         v[root->right->val]++;
//         dfs(root->right,v);
//         v[root->left->val]--;
//         v[root->right->val]--;
//     }
//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<int>v(10,0);
//         dfs(root,v);
//         return count;
//     }
};