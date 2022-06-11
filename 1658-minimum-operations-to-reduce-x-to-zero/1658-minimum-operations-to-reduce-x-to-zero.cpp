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
         int p=accumulate(nums.begin(),nums.end(),0);
            if(p<x)
            {
                return -1;
            }
            vector<long long int>first,second;
        long long int sum=0;
        int ans=INT_MAX;
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
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum+=nums[i];
            second.push_back(sum);
            if(sum==x)
            {
                int n=nums.size();
                ans=min(ans,n-i);
            }
        }
        reverse(second.begin(),second.end());
        for(int i=0;i<first.size();i++)
        {
            long long int temp=x-first[i];
            long long int t=lower_bound(second.begin(),second.end(),temp)-second.begin();
            if(t<second.size() and second[t]==temp)
            {
                int value=i+1+second.size()-t-1;
                ans=min(ans,value);
            }
        }
          for(int i=0;i<first.size();i++)
        {
            long long int temp=x-second[i];
            long long int t=lower_bound(first.begin(),first.end(),temp)-first.begin();
            if(t<first.size() and first[t]==temp)
            {
                int value=first.size()-i+t+1;
                ans=min(ans,value);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};