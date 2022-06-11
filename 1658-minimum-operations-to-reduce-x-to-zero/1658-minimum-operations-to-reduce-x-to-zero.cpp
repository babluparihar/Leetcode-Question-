class Solution {
public:
    // // so finally got the recursion steps
    // vector<vector< int>>dp;
    // long long int solve(vector<int>&nums,int start,int end,long long int x)
    // {
    //     if(start>end or x<0)
    //     {
    //         // not possible 
    //         return INT_MAX/2;
    //     }
    //     if(x==0)
    //     {
    //         // possible so return 0
    //         return 0;
    //     }t
    //     if(dp[start][end]!=-1)
    //     {
    //         return dp[start][end];
    //     }
    //     // choose from start
    //     long long int temp1=x-nums[start];
    //     long long int temp2=x-nums[end];
    //     long long int a=1+solve(nums,start+1,end,temp1);
    //     long long int b=1+solve(nums,start,end-1,temp2);
    //     return dp[start][end]=min(a,b);
    // }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s<x)
        {
            return -1;
        }
        vector<long long int>first;
        long long sum=0;
        int  ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
        sum+=nums[i];
        first.push_back(sum);
        if(sum==x)
        {
            ans=min(ans,i+1);
        }
        }
        sum=0;
        vector<long long int>second(nums.size());
        for(int i=nums.size()-1;i>=0;i--)
        {
        sum+=nums[i];
        second[i]=sum;
        if(sum==x)
        {
            ans=min(ans,n-i);
        }
        }
        
        
        
        for(int i=0;i<first.size();i++)
        {
            int temp=x-first[i];
            int t=lower_bound(second.begin(),second.end(),temp)-second.begin();
            if(t<n and second[t]==temp)
            {
                    ans=min(ans,i+1+n-t);
            }
        }
          for(int i=0;i<first.size();i++)
        {
            int temp=x-second[i];
            int t=lower_bound(first.begin(),first.end(),temp)-first.begin();
            if(t<n and first[t]==temp)
            {
                    int ss=n-i;
                    int ff=t+1;
                    ans=min(ans,ss+ff);
            }
        }
        return ans==INT_MAX ?-1:ans;
    }
};