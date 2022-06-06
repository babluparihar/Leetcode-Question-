class Solution {
public:
    int minDistance(string a, string b) {
        int dp[a.size()+1][b.size()+1];
        for(int i=0;i<=a.size();i++)
        {
            for(int j=0;j<=b.size();j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1])
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
        int m=a.size();
        int n=b.size();
        int nn=dp[m][n];
        return abs(nn-m)+abs(nn-n);
    }
};