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
   

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

//     int countNodes(TreeNode* root) {
//         if(root==NULL)return 0;
//         int count= 0;
//         queue<TreeNode*>q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             auto node = q.front();
//             q.pop();
//             count++;
//             if(node->left==NULL){
//                 return q.size()+count;
//             }
//             else
//             {
//                 q.push(node->left);
//             }
//             if(node->right==NULL){
//                 return q.size()+count;
//             }
//             else q.push(node->right);
//         }
//         return count;
//     }
};