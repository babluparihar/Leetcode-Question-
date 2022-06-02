class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& vec) {
        vector<vector<int>>ans;
        for(int i=0;i<vec[0].size();i++)
        {
            vector<int>v;
            for(int j=0;j<vec.size();j++)
            {
                v.push_back(vec[j][i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};