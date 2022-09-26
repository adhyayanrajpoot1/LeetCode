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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)return -1;
        queue<TreeNode*>q;
        q.push(root);
        int ans=-1;
        while(!q.empty())
        {
            int size = q.size();
            //vector<int>temp;
            for(int i = 0 ; i < size ; i++)
            {
                auto front = q.front();
                q.pop();
                //temp.push_back(front->val);
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
                if(i==0)ans = front->val;
            }
            //if(temp.size()>0)
            //ans = temp[0];
            
        }
        return ans;
        
    }
};