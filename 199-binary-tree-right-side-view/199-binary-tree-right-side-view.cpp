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
    vector<int>ans;
    void level_order(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        int x=0;
        while(!q.empty())
        {
            int curr=q.size();
            for(int i=0;i<curr;i++)
            {
                TreeNode* p=q.front();
                q.pop();
                x=p->val;
                if(p->left!=NULL)
                {
                    q.push(p->left);
                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
            ans.push_back(x);
            if(q.size()==0)
            {
                return;
            }
        }
      
          ans.push_back(x);
    }
    vector<int> rightSideView(TreeNode* root) {
        level_order(root);
        return ans;
    }
};