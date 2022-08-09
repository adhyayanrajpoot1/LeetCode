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
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        //stack<TreeNode*>s;
        queue<TreeNode*>q;
        q.push(root);
        int i = 0;
        while(!q.empty())
        {
            vector<int>v;
            int size = q.size();
            for(int i= 0 ; i < size ; i++)
            {
                TreeNode*front = q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);

            }
            
            if(i%2!=0)
            {
                reverse(v.begin(),v.end());
                i++;
            }
            else{
                i++;
            }
            ans.push_back(v);
        }
        return ans;
    }
};