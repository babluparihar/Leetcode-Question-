class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int count=0;
        while(i<nums.size())
        {
            int x=nums[i];
            while(i<nums.size() and x+k>=nums[i])
            {
                i++;
            }
            count++;
        }
        return count;
    }
};