class Solution {
public:
    int minDeletions(string s) {
        vector<int>vec(26,0);
        for(auto i:s)
        {
            vec[i-'a']++;
        }
        
        int ans=0
            ;
        sort(vec.begin(),vec.end());
        for(int i=24;i>=0;i--)
        {
             if(vec[i]<=0)
            {
                break;
            }
            if(vec[i]>=vec[i+1])
            {
                int prev=vec[i];
                vec[i]=max(0,vec[i+1]-1);
                ans+=(prev-vec[i]);
            }
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // // this is using priority queue but we can solve it by using less number of operation
        // priority_queue<pair<int,char>>q;     // this is sorted on the basis of the  element frequency
        // for(int i=0;i<26;i++)
        // {
        //     q.push({vec[i],i+'a'});
        // }
        // int mx=q.top().first;
        // q.pop();
        // int ans=0;
        // while(!q.empty())
        // {
        //     while(q.top().first==mx)
        //     {
        //         auto x=q.top();
        //         x.first--;
        //         q.pop();
        //         q.push(x);
        //         ans++;
        //     }
        //     mx=q.top().first;
        //     q.pop();
        //     if(mx<=0)
        //     {
        //         break;
        //     }
        // }
        // return ans;
    }
};