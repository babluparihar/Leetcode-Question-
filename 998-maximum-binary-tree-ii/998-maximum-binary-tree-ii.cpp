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
    vector<int>vec;
    void inorder(TreeNode *root)
    {
        if(root)
        {
            inorder(root->left);
            vec.push_back(root->val);
            inorder(root->right);
        }
    }
    TreeNode *helper(int l,int r,vector<int>&vec)
    {
        if(l>r or l<0 or r>=vec.size())
        {
            return NULL;
        }
        int ele=0;
        int ind=0;
        for(int i=l;i<=r;i++)
        {
            if(ele<=vec[i])
            {
                ele=vec[i];
                ind=i;
            }
        }
        TreeNode *root=new TreeNode(ele);
        root->left=helper(l,ind-1,vec);
        root->right=helper(ind+1,r,vec);
        return root;
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        inorder(root);
        vec.push_back(val);
        int ele=*max_element(vec.begin(),vec.end());
        int ind=max_element(vec.begin(),vec.end())-vec.begin();
        TreeNode *rr=new TreeNode(ele);
        rr->left=helper(0,ind-1,vec);
        rr->right=helper(ind+1,vec.size()-1,vec);
        return rr;
    }
};