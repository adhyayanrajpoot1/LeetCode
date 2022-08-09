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
    vector<string>ans;
    void f(TreeNode*root , string s)
    {
        if(root==NULL)return;
        if( root->left==NULL && root->right==NULL){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val);
        s+="->";
        f(root->left,s);
        f(root->right , s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)return {""};
        f(root,"");
        return ans;
    }
};