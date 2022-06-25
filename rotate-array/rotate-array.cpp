class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // so already told that tree ways to solve this problem
        // i got it
        
        // first solution
        
        if(k==0)
        {
            return ;
        }
        else
        {
            int i=0;
            int j=nums.size()-1;
            k=k%nums.size();
            int t=k;
            while(i<=j and t--)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            reverse(nums.begin(),nums.begin()+k);
            reverse(nums.begin()+k,nums.end());
            reverse(nums.begin()+2*k,nums.end());
        }
        
    }
};