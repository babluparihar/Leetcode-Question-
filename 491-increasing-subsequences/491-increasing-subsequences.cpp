class Solution {
public:
    vector<vector<int>>res;
     map<vector<int>,int>m;
    void bt(vector<int>&nums,int i,vector<int>temp)
    {
           if(temp.size()>=2 and m[temp]!=1)
        {
            m[temp]++;
            res.push_back(temp);
        }
        if(i==nums.size())
        {
            return ;
        }
     
        for(int j=i;j<nums.size();j++)
        {
            if(temp.size()==0 or (temp[temp.size()-1]<=nums[j]))
            {
                temp.push_back(nums[j]);
                bt(nums,j+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        bt(nums,0,{});
        return res;
    }
};