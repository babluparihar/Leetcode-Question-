class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&matrix,int i,int j)
    {
          if(i==matrix.size()-1 and j>=0 and j<matrix.size())
           {
               return matrix[i][j];
           }
           if(j>=matrix[0].size() or j<0)
           {
               return INT_MAX;
           }
        if(dp[i][j]!=INT_MAX)
        {
            return dp[i][j];
        }
        int a=solve(matrix,i+1,j+1);
        int b=solve(matrix,i+1,j);
        int c=solve(matrix,i+1,j-1);
        return dp[i][j]=matrix[i][j]+min({a,b,c});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)
        {
           int x=solve(matrix,0,i);
           ans=min(ans,x);
        }
        // for(auto i:dp)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};