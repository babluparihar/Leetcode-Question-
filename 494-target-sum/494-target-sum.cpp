class Solution {
public:
    vector<vector<int>>dp;
    // int fun(vector<int>&nums,int sum,int n)
    // {
    //     if(sum<=0)
    //     {
    //         return dp[n][sum]=1;
    //     }
    //     if(n<=0)
    //     {
    //         return dp[n][sum]=0;
    //     }
    //     if(nums[n-1]<=sum)
    //     {
    //         int a=fun(nums,sum-nums[n-1],n-1);
    //         int b=fun(nums,sum,n-1);
    //         return dp[n][sum]=a+b;
    //     }
    //     else
    //     {
    //         return dp[n][sum]=fun(nums,sum,n-1);
    //     }
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(abs(s+target)%2!=0 or s<target)
        {
            return 0;
        }
        int sum=abs(s+target)/2;
        dp.resize(nums.size()+1,vector<int>(sum+1,0));
           for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<=sum;j++)
            {
                 if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=0;j<=sum;j++)
            {
                 if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][sum];
    }
};