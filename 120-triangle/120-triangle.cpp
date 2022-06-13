class Solution {
public:
    int n;
    vector<vector<int>>nums;
    vector<vector<int>>dp;
    int solve(int i,int ind)
    {
        if(ind>=n)
        {
            return 0;
        }
        if(i>=nums[ind].size())
        {
            // invalid input
            return INT_MAX;
        }
        if(dp[ind][i]!=-1)
        {
            return dp[ind][i];
        }
        return dp[ind][i]=min(nums[ind][i]+solve(i,ind+1),nums[ind][i]+solve(i+1,ind+1));
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        nums.assign(triangle.begin(),triangle.end());
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,0);
    }
};