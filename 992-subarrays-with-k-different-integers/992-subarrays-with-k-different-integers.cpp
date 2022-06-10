class Solution {
public:
    int solve(vector<int>&nums,int k)
    {
        unordered_map<int,int>m;
        int left=0;
        int right=0;
        int ans=0;
        while(right<nums.size())
        {
            m[nums[right]]++;
            while(m.size()>k)
            {
                m[nums[left]]--;
                if(m[nums[left]]==0)
                {
                    m.erase(nums[left]);
                }
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return solve(nums,k)-solve(nums,k-1);
    }
};