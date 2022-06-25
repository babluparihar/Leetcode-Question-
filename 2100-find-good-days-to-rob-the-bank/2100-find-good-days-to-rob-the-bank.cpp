class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        if(2*time>=nums.size())
        {
            return {};
        }
        vector<int>ans;
        vector<int>first(nums.size(),0);
        vector<int>second(nums.size(),0);
        int past=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(past>=nums[i])
            {
                first[i]+=first[i-1];
                first[i]++;
            }
            past=nums[i];
        }
        past=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(past>=nums[i])
            {
                second[i]+=second[i+1];
                second[i]++;
            }
            past=nums[i];
        }
        for(int i=time;i<nums.size()-time;i++)
        {
            if(first[i]>=time and second[i]>=time)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};