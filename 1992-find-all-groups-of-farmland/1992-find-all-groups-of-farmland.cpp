class Solution {
public:
    int first;
    int second;
    void dfs(int r,int c,int row,int col,vector<vector<int>>&visited,vector<vector<int>>&land)
    {
        if(r<0 or r>=row or c<0 or c>=col or visited[r][c]==1 or land[r][c]==0)
        {
            return;
        }
        first=max(first,r);
        second=max(second,c);
        visited[r][c]=true;
        dfs(r-1,c,row,col,visited,land);
        dfs(r,c+1,row,col,visited,land);
        dfs(r+1,c,row,col,visited,land);
        dfs(r,c-1,row,col,visited,land);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>visited(land.size(),vector<int>(land[0].size(),0));
        vector<vector<int>>ans;
        int n=land.size();
        int m=land[0].size();
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[i].size();j++)
            {
                if(land[i][j]==1 and visited[i][j]==0)
                {
                    vector<int>vec;
                    vec.push_back(i);
                    vec.push_back(j);
                    first=INT_MIN;
                    second=INT_MIN;
                    dfs(i,j,n,m,visited,land);
                    vec.push_back(first);
                    vec.push_back(second);
                    ans.push_back(vec);
                }
            }
        }
        return ans;
    }
};