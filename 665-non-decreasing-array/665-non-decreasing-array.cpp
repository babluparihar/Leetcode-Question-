class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=2)
        {
            return true;
        }        
        int past1=nums[0];
        int past2=INT_MIN;
        int count=0;
        for(int i=1;i<nums.size();i++)
        {
           if(past1>nums[i])
           {
               if(i+1==nums.size() and count==0)
               {
                   return true;
               }
               if(i+1<nums.size() and past1<=nums[i+1])
               {
                   // do nothing
                   count++;
                   int temp=past1;
                   past1=nums[i+1];
                   past2=temp;
               }
               else if(nums[i]>=past2)
               {
                   count++;
                   int temp=past1;
                   past1=nums[i];
               }
               else
               {
                   return false;
               }
           }
           else
           {
               int temp=past1;
               past1=nums[i];
               past2=temp;
           }
        }
        return count<=1;
    }
};