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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        if(root==NULL)return NULL;
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            if(curr!=NULL && curr->left)
                s.push(curr->left);
            if(curr &&curr->right)
                s.push(curr->right);
            swap(curr->left, curr->right);
        }
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root==NULL)return NULL;
//         swap(root->left , root->right);
//         invertTree(root->left);
//         invertTree(root->right);
//         return root;
//     }
// };