
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);    
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          
                else if (root->left==NULL)
                    return root->right;
                else if (root->right==NULL)
                    return root->left;  
                else{
                    TreeNode* temp = root->left;                       
                    while(temp->right != NULL) temp = temp->right;   
                    root->val = temp->val;                           
                    root->left = deleteNode(root->left, temp->val);
                }
            }
        return root;
    }   
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* f(TreeNode*root , int key)
//     {
//         if(root==NULL)return NULL;
//         if(root->val == key){
//             if(root->left==NULL && root->right==NULL)
//             {
//                 //delete root;
//                 return root = NULL;
//             }
//             else if(root->left==NULL)
//             {
//                 swap(root->val,root->right->val);
//                 root->right=NULL;
                
//             }
//             else if(root->right==NULL)
//             {
//                 swap(root->val,root->left->val);
//                 root->left=NULL;
//             }
//             else{
                
//                 TreeNode*temp = root->left;
//                 TreeNode*ava;
//                 while(temp!=NULL)
//                 {
//                     ava = temp;
//                     temp = temp->right;
//                 }
//                 swap(root->val,ava->val);
//                 f(root,ava->val); 
//             }
            
//         }
//         else{
//             root->left = f(root->left,key);
//             root->right = f(root->right,key);
            
//         }return root;
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root==NULL)return NULL;
//         if(root->left==NULL && root->right==NULL) if(root->val==key)return NULL;
//         f(root,key);
//         return root;
//     }
// };