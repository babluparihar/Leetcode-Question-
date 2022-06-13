class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string &a,string &b,string &c,int i,int j,int k)
    {
        // base case
        if(k>=c.size())
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(a[i]==c[k] and b[j]==c[k])
        {
            bool aa=solve(a,b,c,i+1,j,k+1);
            bool bb=solve(a,b,c,i,j+1,k+1);
            if(!aa and !bb)
            {
                return dp[i][j]= false;
            }
            return dp[i][j]= true;
        }
        else if(a[i]==c[k] and  b[j]!=c[k])
        {
            return dp[i][j]= solve(a,b,c,i+1,j,k+1);
        }
        else if(a[i]!=c[k] and b[j]==c[k])
        {
            return dp[i][j]= solve(a,b,c,i,j+1,k+1);
        }
        else
        {
            return dp[i][j]=false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size())
        {
            return false;
        }
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,0,0,0);
    }
};