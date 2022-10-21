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
    TreeNode* f(vector<int>&pre , vector<int>&in , int s , int e , int &index)
    {
        if(s>e)return NULL;
        int div = 0;
        TreeNode*node = new TreeNode(pre[index]);
        for(int i = s ; i <= e ; i++)
        {
            if(in[i]==pre[index])
            {
                div = i;
                break;
            }
        }
        index++;
        node->left = f(pre,in,s,div-1,index);
        node->right = f(pre,in,div+1,e,index);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return f(preorder,inorder,0,inorder.size()-1 , index);
    }
};