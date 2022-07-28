You might be doing the same mistake that I did, using INT_MAX, INT_MIN.
My first solution :
​
class Solution {
public:
bool isValidBST(TreeNode* root) {
return fun(root, INT_MAX, INT_MIN);
}
bool fun(TreeNode* root, int max, int min){
if(root==NULL){
return true;
}
if(root->val > min && root->val < max){
//checking recursively the left and right-subtree, are they BST??
// if both subtree are BST, then Parent tree is also BST
return fun(root->left, root->val, min) && fun(root->right, max, root->val);
}
return false;
}
};
But I did a silly mistake here, The constraint given is from -2^31 to 2^31-1, and INT_MAX = 2^31-1 and INT_MIN = -2^31.
In this case, it will fail.
​
Better approach is, that will never fail at any constartint is using the reference for minNode, and maxNode. Actually this is the basic concept here to be used, first one is dependent on the constraint.
Following this approach, we came up to this solution:
​
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
bool isValidBST(TreeNode* root) {
return fun(root, NULL, NULL);
}
bool fun(TreeNode* root, TreeNode* max, TreeNode* min){
if(root==NULL){
return true;
}
// Using the same above logic
//Just check if max or min-node is NULL, then follow it as true
if((min==NULL || root->val > min->val) && (max==NULL || root->val < max->val)){
return fun(root->left, root, min) && fun(root->right, max, root);
}
return false;
}
};