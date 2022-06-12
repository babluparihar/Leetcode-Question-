class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        for(int i=0;i<op.size();i++)
        {
            int x=m[op[i][0]];
            m.erase(op[i][0]);
            m[op[i][1]]=x;
        }
        vector<int>ans(nums.size());
        for(auto i:m)
        {
            ans[i.second]=i.first;
        }
        return ans;
    }
};