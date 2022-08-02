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
    TreeNode*f(vector<int>& preorder,int&pi, vector<int>& inorder,int il ,int ir)
    {
        if(il>ir)return NULL;
        TreeNode* root=new TreeNode(preorder[pi]);
        int index;
        for(int i = il ; i <= ir ; i++)
        {
            if(inorder[i]==root->val)
            {
                index = i;
                break;
            }
        }
        pi++;
        root->left = f(preorder,pi,inorder,il,index-1);
        root->right = f(preorder,pi,inorder,index+1,ir);
         
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pi=0;
        return f(preorder,pi,inorder,0,inorder.size()-1);
    }
};