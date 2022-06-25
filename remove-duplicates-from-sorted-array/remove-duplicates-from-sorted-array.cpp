class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two method
        // firs set
        // two pointer
        
        //using set
        set<int>s;
        for(auto i:nums)
        {
            s.insert(i);
        }
        auto it=s.begin();
        for(int i=0;i<s.size();i++)
        {
            nums[i]=*it;
            it++;
        }
        return s.size();
        
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