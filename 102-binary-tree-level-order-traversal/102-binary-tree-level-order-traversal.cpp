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
    void bfs(TreeNode*root)
    {
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int>v;
            for(int i = 0 ; i < size ; i++)
            {
                TreeNode*front = q.front();
                v.push_back(front->val);
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                
            }
            ans.push_back(v);
        }
        return ans;
    }
};