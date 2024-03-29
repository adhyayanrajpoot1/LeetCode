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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        q.push(root);
        if(depth==1)
        {
            TreeNode*head = new TreeNode(val);
            head->left = root;
            return head;
        }
        int level = 1;
        while(!q.empty())
        {
            level++;
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                auto front = q.front();
                q.pop();
                if(level==depth)
                {
                    TreeNode*l = front->left;
                    TreeNode*r = front->right;
                    TreeNode*newL = new TreeNode(val);
                    TreeNode*newR = new TreeNode(val);
                    front->left = newL;
                    front->left->left = l;
                    //newL ->right = l->right;
                    front->right = newR;
                    //newR ->left = r->left;
                    front->right->right=r;
                    //return root;
                    //TreeNode*l,*r;
                    
                }
                else
                {
                    if(front->left)
                        q.push(front->left);
                    if(front->right)
                        q.push(front->right);
                }
            }
        }
        return root;
    }
};

//   TreeNode* addOneRow(TreeNode* root, int v, int d) {
//         if(d==1){
//             TreeNode *newnode = new TreeNode(v);
//             newnode->left=root;
//             return newnode;
//         }
        
//         queue<TreeNode*> q;
//         q.push(root);
    
//         int i=1;
//         while(!q.empty()){
//             i++;
//             if(i==d) break;
//             int size = q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 if(temp->left) q.push(temp->left);
//                 if(temp->right) q.push(temp->right); 
//             }
//         }
        
//         int size=q.size();
//         for(int i=0;i<size;i++){
//             TreeNode* temp=q.front(); q.pop();
//             TreeNode* l = temp->left, *r = temp->right;
//             temp->left= new TreeNode(v);
//             temp->left->left=l;
//             temp->right= new TreeNode(v);
//             temp->right->right=r;
//         }
//         return root;
//     }