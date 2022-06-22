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
    // we have to build the binary tree based on the condition 
    TreeNode* helper(int l,int r,vector<int>&nums)
    {
        // base case
        if(l>r or l<0 or r>=nums.size())
        {
            return NULL;
        }
        int ele=INT_MIN;
        int ind=0;
        for(int i=l;i<=r;i++)
        {
            if(nums[i]>=ele)
            {
                ele=nums[i];
                ind=i;
            }
        }
        TreeNode *root=new TreeNode(ele);
        root->left=helper(l,ind-1,nums);
        root->right=helper(ind+1,r,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int ind=max_element(nums.begin(),nums.end())-nums.begin();
        // cout<<mx<<" "<<ind<<endl;
        TreeNode *root=new TreeNode(mx);
        root->left=helper(0,ind-1,nums);
        root->right=helper(ind+1,nums.size()-1,nums);
        return root;
    }
};