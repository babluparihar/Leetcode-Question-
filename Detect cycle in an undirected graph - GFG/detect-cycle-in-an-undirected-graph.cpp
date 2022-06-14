// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool helper(vector<int>vis,vector<int>adj[],int node)
    {
        if(vis[node]==2)
        {
            return true;
        }
        vis[node]=1;
        for(auto child:adj[node])
        {
            if(vis[child]==1)
            {
                vis[child]=2;
            }
            else
            {
                if(helper(vis,adj,child)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V+1,false);
        // go for all the nodes and check
        for(int i=0;i<V;i++)
        {
            vis[i]=1;
            for(auto child:adj[i])
            {
                if(helper(vis,adj,child)==true)
                {
                    return true;
                }
            }
            vis[i]=0;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends