// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // so this is the bfs traversal same as the level order traversal
        queue<int>q;
        vector<bool>visited(V+1,false);
        vector<int>res;
        visited[0]=true;
        q.push(0);
        while(!q.empty())
        {
            int curr=q.size();
            for(int i=0;i<curr;i++)
            {
                int x=q.front();
                res.push_back(x);
                q.pop();
                for(auto child:adj[x])
                {
                    if(visited[child]==false)
                    {
                        q.push(child);
                        visited[child]=true;
                    }
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends