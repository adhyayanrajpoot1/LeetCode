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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            TreeNode*front = q.front().first;
            int ind = q.front().second.first;
            int level = q.front().second.second;
            m[ind][level].insert(front->val);
            q.pop();
            if(front->left)q.push({front->left,{ind-1,level+1}});
            if(front->right)q.push({front->right,{ind+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto it : m)
        {
            vector<int>col;
            for(auto p : it.second)
            {
                //col.insert(col.begin(),p.second.begin(),p.second.end());
                for(auto a : p.second)
                {
                    col.push_back(a) ;
                }
            }
                //cout<<endl;
            
            ans.push_back(col);
        }
        return ans;
    }
};