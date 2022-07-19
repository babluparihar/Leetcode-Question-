class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sum=accumulate(amount.begin(),amount.end(),0);
        return max(*max_element(amount.begin(),amount.end()),(sum+1)/2);
        // priority_queue<int>q;
        // for(auto i:amount)
        // {
        //     q.push(i);
        // }
        // int ans=0;
        // while(true)
        // {
        //     int x=q.top();
        //     q.pop();
        //     int y=q.top();
        //     q.pop();
        //     if(q.top()==0)
        //     {
        //         ans+=(x-y);
        //         return ans;
        //     }
        //     else
        //     {
        //         int diff=q.top();
        //         ans+=diff;
        //         q.push(x-diff);
        //         q.push(y-diff);
        //     }
        // } 
        // return ans;
    }
};