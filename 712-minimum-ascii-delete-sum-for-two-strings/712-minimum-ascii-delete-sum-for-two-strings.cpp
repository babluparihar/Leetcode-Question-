class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
        for(int i=1;i<=a.size();i++)
        {
            for(int j=1;j<=b.size();j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=a[i-1]+b[j-1]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for(auto i:dp)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int x=0;
        int y=0;
        for(auto i:a)
        {
            x+=i;
        }
        for(auto j:b)
        {
            y+=j;
        }
        return x+y-dp[a.size()][b.size()];
        
    }
};