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
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>q;
            for(int i=0;i<nums.size();i++)
            {
                string s=nums[i];
                string x=s.substr(start,len);
                q.push({x,i});
            }
            int f=0;
            while(k-- and q.size()!=0)
            {
                f=q.top().second;
                q.pop();
            }
            ans.push_back(f);
        }
        return ans;
    }
};