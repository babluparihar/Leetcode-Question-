class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&piles,int start,int end)
    {
        // base case
         if(start>end)
         {
             return 0;
         }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        // taking from the last
        int a=piles[end]+max(solve(piles,start,end-2),solve(piles,start+1,end-1));
        int b=piles[start]+max(solve(piles,start+2,end),solve(piles,start+1,end-1));
        return dp[start][end]=max(a,b);
    }
    bool stoneGame(vector<int>& piles) {
        dp.resize(piles.size(),vector<int>(piles.size(),-1));
        int x=solve(piles,0,piles.size()-1);
        int sum=accumulate(piles.begin(),piles.end(),0);
        sum-=x;
        return x>=sum;
    }
};