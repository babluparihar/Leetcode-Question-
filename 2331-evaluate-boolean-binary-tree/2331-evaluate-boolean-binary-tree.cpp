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
    bool evaluateTree(TreeNode* root) {
        if(root->val==2)
        {
            bool first=evaluateTree(root->left);
            bool second=evaluateTree(root->right);
            return (first or second);
        }
        else if(root->val==3)
        {
             bool first=evaluateTree(root->left);
            bool second=evaluateTree(root->right);
            return (first and second);
        }
        else
        {
            return root->val;
        }
    }
};