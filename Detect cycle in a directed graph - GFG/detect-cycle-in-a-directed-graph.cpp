// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
      // showing time limit exceed because of two much recursive call use khans algorithm to detect cyclee
    
    // bool helper(int child,vector<bool>visited,vector<int>adj[])   // so we dont need to pass visited as the reference okay :)
    // {
    //     if(visited[child]==true)
    //     {
    //         return true;
    //     }
    //     // go with flow
    //     visited[child]=true;
    //     for(auto c:adj[child])
    //     {
    //         if(helper(c,visited,adj)==true)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // calculate indegree
        vector<int>ind(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                ind[j]+=1;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto child:adj[curr])
            {
                ind[child]--;
                if(ind[child]==0)
                {
                    q.push(child);
                }
            }
            count++;
        }
        return count!=V;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends