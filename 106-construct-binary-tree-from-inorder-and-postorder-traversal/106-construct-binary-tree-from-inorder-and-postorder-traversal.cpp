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
        //if(index<0)return NULL;
        int div = 0;
        TreeNode*node = new TreeNode(pre[index--]);
        for(int i = s ; i <= e ; i++)
        {
            if(in[i]==node->val)
            {
                div = i;
                break;
            }
        }
        node->right = f(pre,in,div+1,e,index);
        node->left = f(pre,in,s,div-1,index);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = inorder.size()-1;
        return f(postorder,inorder,0,postorder.size()-1,index);
    }
};