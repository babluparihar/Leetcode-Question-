class Solution {
public:
    vector<int>nums;
    int n;
    vector<vector<int>>dp;
    int solve(int i,int s)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][s]!=-1)
        {
            return dp[i][s];
        }
        if(s==true)
        {
            return dp[i][s]=max(-nums[i]+solve(i+1,false),solve(i+1,true));
        }
        else
        {
            return dp[i][s]=max(nums[i]+solve(i+1,true),solve(i+1,false));
        }
    }
    int maxProfit(vector<int>& prices) {
        nums.assign(prices.begin(),prices.end());
        n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(0,true);
    }
};