class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // first solution using the unordered_map
        /*
        vector<int>ans;
        unordered_map<int,int>m;
        for(auto i:nums1)
        {
            m[i]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(m.find(nums2[i])!=m.end())
            {
                ans.push_back(nums2[i]);
                m[nums2[i]]--;
                if(m[nums2[i]]==0)
                {
                    m.erase(nums2[i]);
                }
            }
        }
        return ans; */
        
        //second solution using the sorting technique
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        vector<int>nums;
        while(true)
        {
            // go by minimum element
            while(i<nums1.size() and j<nums2.size() and nums1[i]==nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
                j++;
            }
            if(i<nums1.size() and j<nums2.size() and nums1[i]>nums2[j])
            {
                j++;
            }
            else
            {
               i++;
            }
            if(i>=nums1.size() or j>=nums2.size())
            {
                return nums;
            }
        }
        return nums;
    }
};