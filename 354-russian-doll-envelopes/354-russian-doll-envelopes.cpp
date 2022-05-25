class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto comp = [](const vector<int>& e1, const vector<int>& e2){
            if(e1[0] == e2[0])
                return e1[1] > e2[1];
            else
                return e1[0] < e2[0];
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        int len = envelopes.size();
        vector dp(len, 0);
        for(int i = 0; i < len; i++){
            dp[i] = envelopes[i][1];
        }
        vector<int>vec;
        vec.push_back(dp[0]);
        for(int i=1;i<dp.size();i++)
        {
            if(vec[vec.size()-1]<dp[i])
            {
                vec.push_back(dp[i]);
            }
            else
            {
                auto it=lower_bound(vec.begin(),vec.end(),dp[i]);
                *it=dp[i];
            }
        }
        return vec.size();
    }
};