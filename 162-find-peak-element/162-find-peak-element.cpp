class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        // so go for the binary search algo
        if(nums[0]>nums[1])
        {
            return 0;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2])
        {
            return nums.size()-1;
        }
        int left=1;
        int right=nums.size()-2;
        while(left<=right)
        {
            int mid=(right-left)/2+left;
            if( nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if(nums[mid]<nums[mid-1])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return -1;
    }
};