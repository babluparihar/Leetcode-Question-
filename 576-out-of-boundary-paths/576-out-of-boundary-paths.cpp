class Solution {
public:
    long long int mod=1e9+7;
    vector<vector<vector<int>>>dp;
    int fun(int m,int n,int mm,int r,int c)
    {
        // reached at the answer
        if(r<0 or r>=m or c<0 or c>=n)
        {
            return 1;
        }
        if(mm==0)
        {
            return 0;
        }
        if(dp[r][c][mm]!=-1)
        {
            return dp[r][c][mm];
        }
        int ans=0;
        ans=(ans+fun(m,n,mm-1,r-1,c))%mod;
        ans=(ans+fun(m,n,mm-1,r,c-1))%mod;
        ans=(ans+fun(m,n,mm-1,r+1,c))%mod;
        ans=(ans+fun(m,n,mm-1,r,c+1))%mod;
        return dp[r][c][mm]=ans;
        
    }
    int findPaths(int m, int n, int mm, int r, int c) {
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(mm+1,-1)));
        return fun(m,n,mm,r,c);
    }
};