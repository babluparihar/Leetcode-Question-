class Solution {
public:
    vector<vector<int>>dp;
    bool pal(string &s,int i,int j)
    {
        if(i>=j)
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=pal(s,i+1,j-1);
        }
        return dp[i][j]=false;
    }
    
    string longestPalindrome(string s) {
        dp.resize(s.size()+1,vector<int>(s.size()+1,-1));
         string ans="";
         for(int i=0;i<s.size();i++)
         {
             for(int j=0;j<=i;j++)
             {
                 if(pal(s,j,i)==true and ans.size()<(i-j+1))
                 {
                     ans=s.substr(j,i-j+1);
                 }
             }
         }
        return ans;
     }
};