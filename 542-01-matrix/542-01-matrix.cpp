class Solution {
public:
    // this is the bfs based solution
    /*vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();int m=mat[0].size();
        vector<vector<int>>res(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            for(auto i:dir)
            {
                int x=curr.first+i.first;
                int y=curr.second+i.second;
                if(x>=0 and y>=0 and x<n and y<m and res[x][y]==-1)
                {
                    res[x][y]=res[curr.first][curr.second]+1;
                    q.push({x,y});
                }
            }
        }
        return res;
    }
    */
    
    // this  the dp based solution
       vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
       {
           vector<vector<int>>dp(mat.size(),vector<int>(mat[0].size(),INT_MAX-2));
           for(int i=0;i<mat.size();i++)
           {
               for(int j=0;j<mat[0].size();j++)
               {
                   if(mat[i][j]==0)
                   {
                       dp[i][j]=0;
                   }
                   if(i>0 and dp[i][j]>dp[i-1][j]+1)
                   {
                       dp[i][j]=dp[i-1][j]+1;
                   }
                   if(j>0 and dp[i][j]>1+dp[i][j-1])
                   {
                       dp[i][j]=1+dp[i][j-1];
                   }
               }
           }
            for(int i=mat.size()-1;i>=0;i--)
           {
               for(int j=mat[0].size()-1;j>=0;j--)
               {
                   if(i+1<mat.size() and dp[i][j]>dp[i+1][j]+1)
                   {
                       dp[i][j]=dp[i+1][j]+1;
                   }
                   if(j+1<mat[0].size() and dp[i][j]>1+dp[i][j+1])
                   {
                       dp[i][j]=1+dp[i][j+1];
                   }
               }
           }
           return dp;
       }
};