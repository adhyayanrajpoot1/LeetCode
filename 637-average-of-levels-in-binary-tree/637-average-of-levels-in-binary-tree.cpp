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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<double>v;
        v.push_back(double(root->val));
        while(!q.empty())
        {
            int size = q.size();
            if(size==0)return v;
            double sum = 0;
            double count=0;
            for(int i = 0 ; i < size ; i++)
            {
                auto front = q.front();
                q.pop();
                if(front->left)
                {
                    sum+=front->left->val;
                    q.push(front->left);
                    count++;
                }
                if(front->right)
                {
                    sum+=front->right->val;
                    q.push(front->right);
                    count++;
                }
            }
            if(count)
            //cout << size  << double((double)sum/count)<<endl;
            v.push_back(double((double)sum/count));
            //cout<<q.size()<<" ";
        }
        return v;
    }
};