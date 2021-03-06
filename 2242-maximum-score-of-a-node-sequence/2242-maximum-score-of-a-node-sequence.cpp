class Solution {
public:

    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n=scores.size();
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(auto &l:adj)
        {
            sort(l.begin(),l.end(),[&](const int &a,const int &b){return scores[a]>scores[b];});
            l.resize(min((int)l.size(), 3));  //because we only need top 3 elements whose score is highest  so resize is must step
        }
        int res=-1;
        for(auto &e:edges)
        {
            for(int &i:adj[e[0]])
            {
                for(int &j:adj[e[1]])
                {
                    if(i!=j and i!=e[1] and j!=e[0])
                    {
                        int temp=scores[i]+scores[j]+scores[e[0]]+scores[e[1]];
                        res=max(res,temp);
                    }
                }
            }
        }
        return res;
    }
};