class Solution {
public:
    int n;
    vector<int>nums;
    vector<vector<vector<long long int>>>dp;
    int solve(int i,int s,int c)
    {
        if(i>=n or c>2)
        {
            return 0;
        }
        // if(m.find(key)!=m.end())
        // {
        //     return m[key];
        // }
        if(dp[i][s][c]!=-1)
        {
            return dp[i][s][c];
        }
        if(s==true)
        {
            // mean you can buy
            return dp[i][s][c]=max(-nums[i]+solve(i+1,false,c+1),solve(i+1,true,c));
        }
        else
        {
            return dp[i][s][c]=max(nums[i]+solve(i+1,true,c),solve(i+1,false,c));
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n+1,vector<vector<long long int>>(2,vector<long long int>(3,-1)));
        nums.assign(prices.begin(),prices.end());
        return solve(0,true,0);
    }
};