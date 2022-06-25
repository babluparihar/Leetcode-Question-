class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two method
        // firs set
        // two pointer
        
        // solving using two pointer
        int i=0;
        int j=0;
        int past=nums[0];
        while(j<nums.size())
        {
            while(j<nums.size() and past==nums[j])
            {
                j++;
            }
            nums[i]=nums[j-1];
            past=nums[j];
            i++;
        }
        return i;
    }
};