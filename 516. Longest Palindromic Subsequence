
class Solution {
public:
    vector<vector<int>>dp;
    int rec(string &s,string &t,int i,int j)
    {
        if(i>=s.size() || j>=t.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else if(s[i]==t[j])
        {
            return dp[i][j]=1+rec(s,t,i+1,j+1);
        }
        else
        {
            return dp[i][j]=max(rec(s,t,i,j+1),rec(s,t,i+1,j));
        }
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=t.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        int len=rec(s,t,0,0);
        return len;
    }
};
