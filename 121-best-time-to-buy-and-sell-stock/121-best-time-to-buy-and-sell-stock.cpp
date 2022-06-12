class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int mn=INT_MAX;
        for(auto i:prices)
        {
            mn=min(i,mn);
            ans=max(ans,i-mn);
        }
        return ans;
    }
};