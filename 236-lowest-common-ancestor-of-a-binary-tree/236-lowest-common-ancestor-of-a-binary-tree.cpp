/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if (!root || root == p || root == q) return root;
//     TreeNode* left = lowestCommonAncestor(root->left, p, q);
//     TreeNode* right = lowestCommonAncestor(root->right, p, q);
//     return left==NULL ? right : right==NULL ? left : root;
// }
   bool f(TreeNode*root , TreeNode*temp,vector<TreeNode*>&ans)
    {
        if(root==NULL)return false;
        ans.push_back(root);
        if(root==temp){
            //cout<<"fsjv";
            //ans.push_back(temp);
            return true;
        }
        
        if((root->left && f(root->left,temp,ans))||(root->right && f(root->right , temp,ans))) return true;
        
        
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1,v2;
        if(!f(root,p,v1) ||!f(root,q,v2))return NULL;
        TreeNode*common=NULL;
        int i =0,j=0;
        cout << v1.size() << " " << v2.size()<<endl;
        while(v1.size()>i && v2.size()>j)
        {
            cout << v1[i]->val <<v2[j]->val<<endl;
            if(v1[i]->val==v2[j]->val){
                common = v1[i];
                
                
            }
            i++,j++;
            
        }
        return common;
    //      int i;
    // for (i = 0; i < v1.size() && i < v2.size() ; i++)
    //     if (v1[i] != v2[i])
    //         break;
    // return v1[i-1];
    }
};