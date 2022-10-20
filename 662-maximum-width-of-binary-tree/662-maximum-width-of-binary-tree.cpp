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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,long>>q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty())
        {
            int min = q.front().second;
            int size = q.size();
            int first,second;
            for(int i = 0 ; i < size ; i++)
            {
                long currId = q.front().second-min;
                TreeNode*node = q.front().first;
                q.pop();
                if(i==0)first = currId;
                if(i==size-1)second = currId;
                if(node->left)
                {
                    q.push({node->left,currId*2+1});
                }
                if(node->right)
                {
                    q.push({node->right , currId*2+2});
                }
            }
            ans = max(ans,second-first+1);
        }
        return ans;
    }
};