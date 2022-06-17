class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& a) {
        int n=a.size();
        vector<int>res(n,INT_MAX);
        vector<int>id(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<richer.size();i++)
        {
            int u=richer[i][0];
            int v=richer[i][1];
            adj[u].push_back(v);
            id[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            res[i]=i;
            if(id[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(auto i:adj[t])
            {
                if(res[i]==INT_MAX or a[res[i]]>a[res[t]])
                {
                    res[i]=res[t];
                }
                id[i]--;
                if(id[i]==0)
                {
                    q.push(i);
                }   
            }
        }
        return res;
    }
};