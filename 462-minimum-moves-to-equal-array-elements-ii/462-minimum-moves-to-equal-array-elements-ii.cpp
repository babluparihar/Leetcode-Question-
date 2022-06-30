class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        // reason behind for this problem is that we just need to add or remove so the minimum operation will be that we equal all elements to the middle element
        
        int ele=nums[nums.size()/2];
        int ans=0;
        for(auto i:nums)
        {
            ans+=abs(i-ele);
        }
        return ans;
    }
};