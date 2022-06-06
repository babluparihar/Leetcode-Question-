class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else if(str1[i-1]==str2[j-1])
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
        string ans="";
        int i=n;
        int j=m;
        while(i>0 and j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                ans+=str1[i-1];
                i--;
            }
            else
            {
                ans+=str2[j-1];
                j--;
            }
        }
           while(i>0)
            {
                ans+=str1[i-1];
                i--;
            }
          while(j>0)
            {
                ans+=str2[j-1];
                j--;
            }
        reverse(ans.begin(),ans.end());
        return ans;
     
    }
};