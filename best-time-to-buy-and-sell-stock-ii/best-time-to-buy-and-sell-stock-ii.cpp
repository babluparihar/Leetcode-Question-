class Solution {
public:
    // solving this question using the dynamic programming
    vector<int>nums;
    vector<vector<int>>dp;
    int solve(int i,bool state)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        // if result found
        if(dp[i][state]!=-1)
        {
            return dp[i][state];
        }
        // now depend upon state
        if(state==false)  // sell the stock
        {
            // we have two option
            int first=nums[i]+solve(i+1,true);
            int second=solve(i+1,state);
            return dp[i][state]=max(first,second);
        }
        else
        {
            int first=-nums[i]+solve(i+1,false);
            int second=solve(i+1,state);
            return dp[i][state]=max(first,second);
        }
    }
    int maxProfit(vector<int>& prices) {
        this->nums=prices;
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(0,true);
    }
};