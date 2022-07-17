class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        // using brute force 
        // see the previous example 
        // pointh here is tht if we store every string than that will create the extra space and give as TLE
        vector<int>ans;
        for(auto i:queries)
        {
            vector<pair<string,int>>q;
            for(int j=0;j<nums.size();j++)
            {
                q.push_back({nums[j].substr(nums[0].size()-i[1],i[1]),j});
            }
            sort(q.begin(),q.end());
            ans.push_back(q[i[0]-1].second);
        }
        return ans;
    }
};