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

class node{
    public:
    int leftH;
    int rightH;
    int dia;
};
class Solution {
public:
    int height(TreeNode*root)
    {
        if(root==NULL)return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        return 1+ max(h1,h2);
    }
    int diameterOfBinaryTree(TreeNode*root) {
        if(root==NULL)return -1;
        int h1 = height(root->left);
        int h2 = height(root->right);
        int ans = max(diameterOfBinaryTree(root->left) , diameterOfBinaryTree(root->right));
        ans = max(ans,h1+h2);
        return ans;
    }
    // node f(TreeNode*root)
    // {
    //     if(root==NULL)
    //     {
    //         node small;
    //         small.leftH = 0;
    //         small.rightH = 0;
    //         small.dia = 0;
    //         return small;
    //     }
    //     node a = f(root->left);
    //     node b = f(root->right);
    //     node ans;
    //     int h1 = 1+max(a.leftH , a.rightH);
    //     int h2 = 1+max(b.leftH , b.rightH);
    //     ans.leftH = h1;
    //     ans.rightH = h2;
    //     int diameter = max(a.dia,b.dia);
    //     ans.dia = max(h1+h2 ,diameter);
    //     return ans;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     return f(root).dia;
    // }
};