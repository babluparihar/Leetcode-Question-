class Solution {
public:
    // int fun(vector<pair<int,int>>&vec,int i,int m,int n,unordered_map<string,int>&mp)
    // {
    //     if(i>=vec.size())
    //     {
    //         return 0;
    //     }
    //     string key=to_string(i)+" "+to_string(m)+" "+to_string(n);
    //     if(mp.find(key)!=mp.end())
    //     {
    //         return mp[key];
    //     }
    //     if(m-vec[i].first>=0 and n-vec[i].second>=0)
    //     {
    //         return mp[key]=max(1+fun(vec,i+1,m-vec[i].first,n-vec[i].second,mp),fun(vec,i+1,m,n,mp));
    //     }
    //     else
    //     {
    //         return mp[key]=fun(vec,i+1,m,n,mp);
    //     }
    // }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vec;
        // unordered_map<string,int>mp;
        for(int i=0;i<strs.size();i++)
        {
            int zero=count(strs[i].begin(),strs[i].end(),'0');
            int one=count(strs[i].begin(),strs[i].end(),'1');
            vec.push_back({zero,one});
        }
        // int ans=0;
        // ans=fun(vec,0,m,n,mp);
        // return ans;
        int dp[strs.size()+1][m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=strs.size();i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    int zero=vec[i-1].first;
                    int one=vec[i-1].second;
                    int past=dp[i-1][j][k];
                    if(zero<=j and one<=k)
                    {
                        past=max(past,1+dp[i-1][j-zero][k-one]);
                    }
                    dp[i][j][k]=past;
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};