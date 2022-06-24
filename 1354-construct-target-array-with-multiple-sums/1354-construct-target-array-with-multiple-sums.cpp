class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int sum=0;
        priority_queue<long long int>q;
        for(auto i:target)
        {
            q.push(i);
            sum+=i;
        }
        while(q.top()!=1)
        {
            int value=q.top();
            q.pop();
            sum-=value;  // greatest element ko substract karo
            if(sum==0 or sum>=value)
            {
                return false;
            }
            int old=value%sum;
            if(sum!=1 and old==0)
            {
                return false;
            }
            q.push(old);
            sum+=old;
        }
        return 1;
    }
};