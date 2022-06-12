class Solution {
public:
    // how to change this code to dp
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int ind,bool b_s)
    {
        if(ind>=nums.size())
        {      
           return 0;
        }
        if(dp[ind][b_s]!=-1)
        {
            return dp[ind][b_s];
        }
        if(b_s==true)
        {
            // sell the stock
            return dp[ind][b_s]=max(nums[ind]+solve(nums,ind+2,false),solve(nums,ind+1,true));
        }
        else
        {
            return dp[ind][b_s]=max(-nums[ind]+solve(nums,ind+1,true),solve(nums,ind+1,false));
        }
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,0);
    }
};