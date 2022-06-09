class Solution {
public:
    int minOperations(int n) {
        if(n%2==0)
        {
            int x=n/2;
            int y=x-1;
            x=2*x+1;
            y=2*y+1;
            x=(x+y)/2;
            int ans=0;
            for(int i=0;i<n/2;i++)
            {
                ans+=abs(2*i+1-x);
            }
            return ans;
        }
        else
        {
            int x=n/2;
            x=2*x+1;
            int ans=0;
            for(int i=0;i<n/2;i++)
            {
                ans+=abs(2*i+1-x);
            }
            return ans;
        }
    }
};