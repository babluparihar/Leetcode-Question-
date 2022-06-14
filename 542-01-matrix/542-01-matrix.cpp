class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
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
};