class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=0)
        {
            return nums.size();
        }
        set<int>s;
        for(auto i:nums)
        {
            s.insert(i);
        }
        int ans=0;
        int count=0;
        auto last=s.begin();
        for(auto i=s.begin();i!=s.end();i++)
        {
            if(*i-*last<=1)
            {
                count++;
            }
            else
            {
                ans=max(ans,count);
                count=1;
            }
            last=i;
        }
        ans=max(ans,count);
        return ans;
    }
};