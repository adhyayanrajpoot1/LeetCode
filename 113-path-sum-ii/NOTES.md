class Solution {
public:
// vector to maintenance the nodes in the current path
vector<int> path;
// vector to save all paths that have sum equals to target
vector< vector<int> > ans;
void dfs(TreeNode* curr, int sum,int target)
{
if(!curr)
return;
sum += curr->val;
path.push_back(curr->val);
// if curr Node is a leaf
if(!curr->left && !curr->right)
{
if(sum == target)
ans.push_back(path);
}
else
{
dfs(curr->left,sum,target);
dfs(curr->right,sum,target);
}
path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
ans.clear();
dfs(root,0,targetSum);
return ans;
}
};