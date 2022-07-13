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
    vector<vector<int>>ans;
    void level_order(TreeNode * root)
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
            vector<int>vec;
            while(curr--)
            {
                TreeNode *p=q.front();
                q.pop();
                vec.push_back(p->val);
                if(p->left)
                {
                    q.push(p->left);
                }
                if(p->right)
                {
                    q.push(p->right); 
                }
            }
            ans.push_back(vec);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        level_order(root);
        return ans;
    }
};