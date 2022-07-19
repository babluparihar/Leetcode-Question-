class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>ans;
        for(int i=0;i<s.size();i++)
        {
            int j=i;
            while(j<s.size() and s[j]==s[i])
            {
                j++;
            }
            if(j-i>=3)
            {
              ans.push_back({i,j-1});
            }
            i=j-1;
        }
        return ans;
    }
};