class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // so already told that tree ways to solve this problem
        // i got it
        
        // first solution
        
        // if(k==0)
        // {
        //     return ;
        // }
        // else
        // {
        //     int i=0;
        //     int j=nums.size()-1;
            k=k%nums.size();
        //     int t=k;
        //     while(i<=j and t--)
        //     {
        //         swap(nums[i],nums[j]);
        //         i++;
        //         j--;
        //     }
        //     reverse(nums.begin(),nums.begin()+k);
        //     reverse(nums.begin()+k,nums.end());
        //     reverse(nums.begin()+2*k,nums.end());
        // }
        
        //second solution using space
        
        vector<int>temp(nums);
        int t=nums.size()-k;
        for(int i=0;i<nums.size() and t<nums.size();i++)
        {
            nums[i]=temp[t++];
        }
        t=0;
        for(int i=k;i<nums.size();i++)
        {
            nums[i]=temp[t++];
        }
    }
};