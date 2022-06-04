import numpy as  np
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        first=[];
        second=[];
        for i in grid:
            mx=-1;
            for j in i:
                mx=max(mx,j);
            first.append(mx);
        for i in range(0,len(grid[0])):
            mx=-1
            for j in range (0,len(grid)):
                mx=max(mx,grid[j][i]);
            second.append(mx);
                
        ans=0;
        for i in range(0,len(grid)):
            for j in range (0,len(grid)):
                ans+=min(first[i],second[j])-grid[i][j]
        return ans;