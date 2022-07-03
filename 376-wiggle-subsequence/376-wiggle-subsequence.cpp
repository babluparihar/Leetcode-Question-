class Solution {
public:
    vector<int>nums;
    vector<vector<int>>dp;
    int solve(int i,int state)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i][state]!=-1)
        {
            return dp[i][state];
        }
        // two element check 
        if(i==nums.size()-1)
        {
            return 1;
        }
        if(state)   // go with postive elements
        {
            if(nums[i]<nums[i+1])  // we should include to get the length as max length
            {
                return dp[i][state]=1+solve(i+1,false);
            }
            else
            {
                return dp[i][state]=solve(i+1,true);
            }
        }
        else
        {
            if(nums[i]>nums[i+1])
            {
                return dp[i][state]=1+solve(i+1,true);
            }
            else
            {
                return dp[i][state]=solve(i+1,false);
            }
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        this->nums=nums;
        dp.resize(nums.size()+1,vector<int>(2,-1));
        int a=solve(0,false);
        dp.resize(nums.size()+1,vector<int>(2,-1));
        int b=solve(0,true);
        return max(a,b);

        
        
        
        
        
        
//         // need to take two array to get the length for the elements 
//         // for every elements their is two choice of that element
//         // I have to search for the solution so I could not solve it by using the methods
//         vector<int>up(nums.size(),1);
//         vector<int>down(nums.size(),1);
//         for(int i=1;i<nums.size();i++)
//         {
//             // up position 
//             if(nums[i]>nums[i-1])
//             {
//                 up[i]=down[i-1]+1;
//                 down[i]=down[i-1];
//             }
//             else if(nums[i]<nums[i-1])
//             {
//                 down[i]=up[i-1]+1;
//                 up[i]=up[i-1];
//             }
//             else
//             {
//                 down[i]=down[i-1];
//                 up[i]=up[i-1];
//             }
//         }
//         return max(down[nums.size()-1],up[nums.size()-1]);
    }
};