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
    int sum=0;
    void level_order(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int curr=q.size();
            for(int i=0;i<curr;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                if(p->left!=NULL)
                {
                    q.push(p->left);
                    if(p->left->left==NULL and p->left->right==NULL)
                    {
                        sum+=p->left->val;
                    }
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        level_order(root);
        return sum;
    }
};