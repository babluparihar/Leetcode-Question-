class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // need to take two array to get the length for the elements 
        // for every elements their is two choice of that element
        vector<int>up(nums.size(),1);
        vector<int>down(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            // up position 
            if(nums[i]>nums[i-1])
            {
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }
            else if(nums[i]<nums[i-1])
            {
                down[i]=up[i-1]+1;
                up[i]=up[i-1];
            }
            else
            {
                down[i]=down[i-1];
                up[i]=up[i-1];
            }
        }
        return max(down[nums.size()-1],up[nums.size()-1]);
    }
};