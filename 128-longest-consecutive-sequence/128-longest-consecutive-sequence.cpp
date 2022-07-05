class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int count=1;
        int ans=0;
        int last=nums[0];
        for(int i=1;i<nums.size();i++)
        {
           while(i<nums.size() and nums[i]==last)
           {
               i++;
           }
            if(i<nums.size() and nums[i]-last==1)
            {
            count++;
            }
            else
            {
            ans=max(ans,count);
            count=1;
            }
            last=nums[i];
        }
        ans=max(ans,count);
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // here I am using the set nlogn so also space is consumed
        // set<int>s;
        // for(auto i:nums)
        // {
        //     s.insert(i);
        // }
        // int ans=0;
        // int count=0;
        // auto last=s.begin();
        // for(auto i=s.begin();i!=s.end();i++)
        // {
        //     if(*i-*last<=1)
        //     {
        //         count++;
        //     }
        //     else
        //     {
        //         ans=max(ans,count);
        //         count=1;
        //     }
        //     last=i;
        // }
        // ans=max(ans,count);
        // return ans;
    }
};