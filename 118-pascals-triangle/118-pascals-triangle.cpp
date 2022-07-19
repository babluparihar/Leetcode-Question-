class Solution {
public:
    vector<vector<int>>dp;
    int ele(int n,int r)
    {
        if(n==0 or r==0)
        {
            return 1;
        }
        if(n==r)
        {
            return 1;
        }
        if(dp[n][r]!=-1)
        {
            return dp[n][r];
        }
        return dp[n][r]=ele(n-1,r-1)+ele(n-1,r);
    }
    vector<vector<int>> generate(int rows) {
        dp.resize(rows+1,vector<int>(rows+1,-1));
        vector<vector<int>>ans;
        for(int i=0;i<rows;i++)
        {
            vector<int>vec;
            for(int j=0;j<=i;j++)
            {
                int value=ele(i,j);
                vec.push_back(value);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};