class Solution {
public:
    //     static bool comp(const vector<int>&first,vector<int>&second)
    // {
    //         //sorting based on the second element 
    //     return first[1]<second[1];
    // }
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort(pairs.begin(),pairs.end(),comp);
        // int ans=0;
        // for(int i=0;i<pairs.size();i++)
        // {
        //     int count=1;
        //     int last=pairs[i][1];
        //     // sorted based on the second element
        //     for(int j=i+1;j<pairs.size();j++)
        //     {
        //         if(last<pairs[j][0])
        //         {
        //             count++;
        //             last=pairs[j][1];
        //         }
        //     }
        //     ans=max(ans,count);
        // }
        // return ans;
        sort(pairs.begin(),pairs.end());
        vector<int>dp(pairs.size(),1);
        int ans=1;
        for(int i=0;i<pairs.size();i++)
        {
            for(int j=i+1;j<pairs.size();j++)
            {
                if(pairs[i][1]<pairs[j][0])
                {
                    dp[j]=max(dp[j],dp[i]+1);
                    ans=max(ans,dp[j]);
                }
            }
        }
        return ans;
    }
};