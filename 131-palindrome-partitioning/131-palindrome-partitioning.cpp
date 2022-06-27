class Solution {
public:
    vector<vector<string>>ans;
    string s;
    vector<vector<int>>dp;
    bool pal(string &s,int i,int j)
    {
        if(i>=j){return true;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(s[i]==s[j]){return dp[i][j]=pal(s,i+1,j-1);}
        else{return dp[i][j]=false;}
    }
    void solve(int i,vector<string>&temp)
    {
        if(i>=s.size())
        {
            ans.push_back(temp);
        }
        else
        {
            for(int j=i;j<s.size();j++)
            {
                if(pal(s,i,j))
                {
                    temp.push_back(s.substr(i,j-i+1));
                    solve(j+1,temp);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        this->s=s;
        vector<string>temp;
        solve(0,temp);
        return ans;
    }
};