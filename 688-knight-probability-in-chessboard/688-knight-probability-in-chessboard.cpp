class Solution {
public:
    vector<vector<vector<double>>>dp;
    double fun(int n,int r,int c,int k)
    {
        if(r>=n or r<0 or c>=n or c<0)
        {
            return 0;
        }
        if(k==0)
        {
            return 1; // valid because we moved and got the answer
        }
        if(dp[r][c][k]!=-1)
        {
            return dp[r][c][k];
        }
        double pro=0;
        pro=(fun(n,r+1,c-2,k-1)+fun(n,r+2,c-1,k-1)+fun(n,r+2,c+1,k-1)+fun(n,r+1,c+2,k-1)+fun(n,r-1,c+2,k-1)+fun(n,r-2,c+1,k-1)+fun(n,r-2,c-1,k-1)+fun(n,r-1,c-2,k-1));
        pro=pro/8;
        return dp[r][c][k]=pro;
    }
    double knightProbability(int n, int k, int r, int c) {
        dp.resize(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return fun(n,r,c,k);
    }
};