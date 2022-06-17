class Solution {
public:
    // so thing is that what we have to do
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // every node if any outgoing then that shoul go to the terminal node
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>od(n,0);
        for(int i=0;i<graph.size();i++)
        {
            for(auto j:graph[i])
            {
                adj[j].push_back(i);
                od[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<od.size();i++)
        {
            if(od[i]==0)
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
                od[i]--;
                if(od[i]==0)
                {
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};