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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        int k=1;
        while(!q.empty())
        {
            
            int size = q.size();
            vector<int>small;
            for(int i =0 ; i < size ; i++)
            {
                TreeNode*front = q.front();
                small.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                {
                    q.push(front->right);
                }
                q.pop();
            }
            if(k==1)
            {
                ans.push_back(small);
                k=0;
            }
            else{
                reverse(small.begin(),small.end());
                ans.push_back(small);
                k=1;
            }
            
        }
        return ans;
    }
};