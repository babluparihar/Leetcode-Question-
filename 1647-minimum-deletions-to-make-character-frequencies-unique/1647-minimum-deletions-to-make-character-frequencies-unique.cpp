class Solution {
public:
    int minDeletions(string s) {
        vector<int>vec(26,0);
        for(auto i:s)
        {
            vec[i-'a']++;
        }
        priority_queue<pair<int,char>>q;
        for(int i=0;i<26;i++)
        {
            q.push({vec[i],i+'a'});
        }
        
        // brute force approach 
        
        
        // unordered_map<char,int>m;
        // for(auto i:s)
        // {
        //     m[i]++;
        // }
        // priority_queue<pair<int,char>>q;
        // for(auto i:m)
        // {
        //     q.push({i.second,i.first});
        // }
        int mx=q.top().first;
        q.pop();
        int ans=0;
        while(!q.empty())
        {
            while(q.top().first==mx)
            {
                auto x=q.top();
                x.first--;
                q.pop();
                q.push(x);
                ans++;
            }
            mx=q.top().first;
            q.pop();
            if(mx<=0)
            {
                break;
            }
        }
        return ans;
    }
};