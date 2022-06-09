class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]<target)
            {
                i++;
            }
            else if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else
            {
                  vector<int>vec;
                vec.push_back(i+1);
                vec.push_back(j+1);
                return vec;
             }
        }
        return {};
    }
};