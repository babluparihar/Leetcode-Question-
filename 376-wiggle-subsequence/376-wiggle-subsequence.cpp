class Solution {
public:
    vector<int>nums;
    vector<vector<int>>dp;
    int solve(int i,int state)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i][state]!=-1)
        {
            return dp[i][state];
        }
        // two element check 
        if(i==nums.size()-1)
        {
            return 1;
        }
        if(state)   // go with postive elements
        {
            if(nums[i]<nums[i+1])  // we should include to get the length as max length
            {
                return dp[i][state]=1+solve(i+1,false);
            }
            else
            {
                return dp[i][state]=solve(i+1,true);
            }
        }
        else
        {
            if(nums[i]>nums[i+1])
            {
                return dp[i][state]=1+solve(i+1,true);
            }
            else
            {
                return dp[i][state]=solve(i+1,false);
            }
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        this->nums=nums;
        dp.resize(nums.size()+1,vector<int>(2,-1));
        int a=solve(0,false);
        dp.resize(nums.size()+1,vector<int>(2,-1));
        int b=solve(0,true);
        return max(a,b);
    }
};