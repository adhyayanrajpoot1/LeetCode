DFS Solution
​
class Solution {
public:
int s=0;
int sumEvenGrandparent(TreeNode* root) {
fun(root,NULL,NULL);  //passing the root node with it's parent & grandparent as NULL
return s;
}
void fun(TreeNode* root,TreeNode* parent,TreeNode* grandparent)
{
if(!root) return;  //if root is null then return
if(grandparent && grandparent->val%2==0)  //checking even valued grandparent existance
s+=root->val;
fun(root->left,root,parent);  //calling function for left subtree where root will be the parent & previous parent will act as the grandparent for left subtree of the root.
fun(root->right,root,parent);  //same for right subtree
}
};
BFS Solution
​
class Solution {
public:
int fun(TreeNode* root)  //function to return it's value if exist or return 0
{
return root?root->val:0;
}
int sumEvenGrandparent(TreeNode* root) {
if(!root) return 0;  //returns 0 if root is NULL
queue<TreeNode*> q;
q.push(root);  //push root node into the queue
int sum=0;
while(!q.empty())  //iterate the loop until the queue gets empty
{
TreeNode* temp=q.front();  //retrieving front of queue and pop it
q.pop();
if(temp->val%2==0)  //if it's value will be divisible by 2 then check for it's grandson
{
if(temp->left) sum+=fun(temp->left->left)+fun(temp->left->right);  //if it's left child exist then move to both left and right subtree of temp->left
if(temp->right) sum+=fun(temp->right->left)+fun(temp->right->right);  //if it's right child exist then move to both left and right subtree of temp->right
}
if(temp->left) q.push(temp->left);  //if left child exist then push the left node to the queue
if(temp->right) q.push(temp->right);  //if right child exist then push the right node to the queue
}
return sum;
}
};
​