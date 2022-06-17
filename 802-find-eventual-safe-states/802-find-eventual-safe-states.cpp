class Solution {
public:
    // so thing is that what we have to do
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // every node if any outgoing then that shoul go to the terminal node
        
        // performed by using the reversing the graph
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>id(n,0);
        for(int i=0;i<graph.size();i++)
        {
            for(auto j:graph[i])
            {
                adj[j].push_back(i);
                id[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<id.size();i++)
        {
            if(id[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto i:adj[t])
            {
                id[i]--;
                if(id[i]==0)
                {
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};