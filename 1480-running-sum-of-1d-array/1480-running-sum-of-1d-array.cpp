class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>vec;
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
            vec.push_back(sum);
        }
        return vec;
    }
};