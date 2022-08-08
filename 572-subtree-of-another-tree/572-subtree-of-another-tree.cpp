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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(!s) return false;
        if (s->val==t->val && isSame(s,t)) return true;
        
        return isSubtree(s->left,t) || isSubtree(s->right,t);
        
    }
    bool isSame(TreeNode *s, TreeNode *t)
    {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        
        return isSame(s->left, t->left) && isSame(s->right, t->right);
        
    }
//     bool check(TreeNode*root1 , TreeNode*root2)
//     {
//         if(root1==NULL && root2==NULL)return true;
//         if(root1==NULL || root2==NULL)return false;
//         if(check(root1->left , root2->left)&& check(root1->right,root2->right))return true;
//         return false;
//     }
//     TreeNode*f(TreeNode*root1 , TreeNode*root2)
//     {
//         if(root1==NULL)return NULL;
        
//         TreeNode*r1 = f(root1->left,root2);
//         if(r1!=NULL)return r1;
//         if(root1->val==root2->val){
//             cout << root1->val <<" ";
//             return root1;
//         }
//         TreeNode*r2 = f(root1->right,root2);
//         return r2;
        
//     }
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         TreeNode*newRoot = f(root,subRoot);
//         if(newRoot==NULL)return false;
        
//         return check(newRoot , subRoot);
//     }
};