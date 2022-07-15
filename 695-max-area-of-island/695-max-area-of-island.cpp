class Solution {
public:
    int ans=0;
    vector<vector<int>>grid;
    vector<vector<int>>visited;
    void dfs(int r,int c,int &count)
    {
        if(r<0 or c<0 or r>=visited.size() or c>=visited[0].size() or visited[r][c]==1 or grid[r][c]==0)
        {
            return;
        }
        visited[r][c]=1;
        count+=1;
        dfs(r-1,c,count);
        dfs(r+1,c,count);
        dfs(r,c+1,count);
        dfs(r,c-1,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid=grid;
        visited.resize(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visited[i][j]==0 and grid[i][j]==1)
                {
                    int count=0;
                    dfs(i,j,count);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};