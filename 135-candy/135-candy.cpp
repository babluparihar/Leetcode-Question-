class Solution {
public:
    int candy(vector<int>& nums) {
        vector<int>res(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
           if(nums[i]>nums[i-1])
           {
               res[i]=1+res[i-1];
           }
        }
        vector<int>ress(nums.size(),1);
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                ress[i]=ress[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<res.size();i++)
        {
            ans+=max(res[i],ress[i]);
        }
        return ans;
    }
};
// [1,0,2,1,2,2,3,4,1,3]