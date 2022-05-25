class Solution {
public:
    static bool comp(const vector<int>&first,const vector<int>&second)
    {
       if(first[0]==second[0])
       {
           return first[1]>second[1];
       }
        return first[0]<second[0];
    }
    int maxEnvelopes(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),comp);
        vector<int>first;
        for(int i=0;i<nums.size();i++)
        {
            first.push_back(nums[i][1]);
        }
        vector<int>second;
        second.push_back(first[0]);
        for(int i=1;i<first.size();i++)
        {
            if(second[second.size()-1]<first[i])
            {
                second.push_back(first[i]);
            }
               else
            {
                auto it=lower_bound(second.begin(),second.end(),first[i]);
                *it=first[i];
            }
        }
        return second.size();
    }
};