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
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return left==NULL ? right : right==NULL ? left : root;
}
//      bool f(vector<TreeNode*>&ans , TreeNode*root , TreeNode*temp)
//     {
//         if(root==NULL)return false;
//         ans.push_back(root);
//         if(root==temp){
//             //cout<<"fsjv";
//             //ans.push_back(temp);
//             return true;
//         }
        
//         if((f(ans,root->left,temp))||(f(ans,root->right , temp))) return true;
        
        
//         ans.pop_back();
//         return false;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*>arr1,arr2;
//         f(arr1 , root , p);
//         f(arr2 , root , q);
//         for(int i = 0 ; i < arr1.size() ; i++)cout << arr1[i]->val << " ";
//         cout<<endl;
//         for(int i = 0 ; i < arr2.size() ; i++)cout << arr2[i]->val << " ";
//         cout<<endl;
//         int i = 0 , j = 0;
//         TreeNode*ans=NULL;
//         while(i < arr1.size() && j < arr2.size()){
//             if(arr1[i]==arr2[j]){
//                 cout << arr1[i]->val<<" ";
//                 ans = arr1[i];
                
                
//             }
//             i++,j++;
//             //else break;
//         }
//         return ans;
        
//     }
};