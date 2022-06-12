class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int f;
    vector<int>nums;
    int solve(int i,bool s)
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
            // we can buy
            return dp[i][s]=max(-nums[i]+solve(i+1,false),solve(i+1,true));
        }
        else
        {
            return dp[i][s]=max(nums[i]-f+solve(i+1,true),solve(i+1,false));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        f=fee;
        nums.assign(prices.begin(),prices.end());
        return solve(0,true);
    }
};