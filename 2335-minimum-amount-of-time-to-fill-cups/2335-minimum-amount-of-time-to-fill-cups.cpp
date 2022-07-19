class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>q;
        for(auto i:amount)
        {
            q.push(i);
        }
        int ans=0;
        while(true)
        {
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            if(y==0)
            {
                ans+=x;
                return ans;
            }
            else
            {
                x--;
                y--;
                ans++;
                q.push(x);
                q.push(y);
            }
        } 
        return ans;
    }
};