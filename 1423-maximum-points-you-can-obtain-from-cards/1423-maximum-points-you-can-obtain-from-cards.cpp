class Solution {
private:
public:
 
    int maxScore(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int window=0;
        for(int i=0;i<(nums.size()-k);i++)
        {
            window+=nums[i];
        }
        int j=0;
        int ans=sum-window;
        for(int i=(nums.size()-k);i<nums.size();i++)
        {
            window-=nums[j++];
            window+=nums[i];
            ans=max(ans,sum-window);
        }
        return ans;
    }
};