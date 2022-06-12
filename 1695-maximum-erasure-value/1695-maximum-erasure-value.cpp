class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>m;
        int sum=0;
        int i=0;
        int j=0;
        int ans=0;
        while(j<nums.size())
        {
            m[nums[j]]++;
            while(i<nums.size() and m[nums[j]]>1)
            {
                sum-=nums[i];
                m[nums[i]]--;
                if(m[nums[i]]==0)
                {
                    m.erase(nums[i]);
                }
                i++;
            }
            sum+=nums[j];
            j++;
            ans=max(ans,sum);
        }
        return ans;
    }
};