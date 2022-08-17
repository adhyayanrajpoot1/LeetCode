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
    vector<int>ans;
    void printAtLevelK(TreeNode*root , TreeNode*target , int k){
        if(root==NULL)return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        printAtLevelK(root->left , target,k-1);
        printAtLevelK(root->right , target,k-1);
    }
    int distance(TreeNode* root, TreeNode* target, int k){
        if(root==NULL)return -1;
        if(root==target){
            printAtLevelK(root,target,k);
            return 0;
        }
        int dl = distance(root->left , target , k);
        if(dl!=-1){
            if(dl+1==k){
                ans.push_back(root->val);
            }
            else{
                printAtLevelK(root->right,target,k-2-dl);
            }
            return 1+dl;
        }
        int dr = distance(root->right , target , k);
        if(dr!=-1){
            if(dr+1==k){
                ans.push_back(root->val);
            }
            else{
                printAtLevelK(root->left,target,k-2-dr);
            }
            return 1+dr;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        distance(root,target,k);
        return ans;
    }
};