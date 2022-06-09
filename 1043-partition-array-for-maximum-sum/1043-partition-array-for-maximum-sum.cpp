class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&arr,int count,int i,int j)
    {
        
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int len=0;
        int curr_max=0;
        int ans=0;
        // this should not be greater than that count
        for(int k=i;k<=j and len<count;k++,len++)
        {
            curr_max=max(curr_max,arr[k]);
            int r=solve(arr,count,k+1,j);
            ans=max(ans,curr_max*(len+1)+r);
        }
        return dp[i][j]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size()+1,vector<int>(arr.size()+1,-1));
        return solve(arr,k,0,arr.size()-1);
    }
};