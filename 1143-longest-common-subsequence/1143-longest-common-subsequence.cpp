class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int dp[b.size()+1][a.size()+1];
        for(int i=0;i<=b.size();i++)
        {
            for(int j=0;j<=a.size();j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else if(b[i-1]==a[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else if(dp[i-1][j]>=dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[b.size()][a.size()];
    }
};