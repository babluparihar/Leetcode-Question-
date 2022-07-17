class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // using brute force 
        vector<int>ans;
        for(auto i:queries)
        {
            int k=i[0];
            int len=i[1];
            int start=nums[0].size()-len;
            vector<pair<string,int>>q;
            for(int i=0;i<nums.size();i++)
            {
                q.push_back({nums[i].substr(start,len),i});
            }
            sort(q.begin(),q.end());
            ans.push_back(q[k-1].second);
        }
        return ans;
    }
};