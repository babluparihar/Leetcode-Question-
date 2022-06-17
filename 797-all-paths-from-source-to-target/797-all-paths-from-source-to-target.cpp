class Solution {
public:
    vector<vector<int>>ans;
    vector<int>res;
    int target;
        
    void dfs(vector<vector<int>>&adj,int node)
    {
        res.push_back(node);
        if(node==target)
        {
            ans.push_back(res);
        }
        else
        {
            for(auto i:adj[node])
            {
                dfs(adj,i);
            }
        }
        res.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        target=n-1;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
       dfs(adj,0);
        return ans;
    }
};