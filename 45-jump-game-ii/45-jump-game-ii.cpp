class Solution {
public:
    int jump(vector<int>& nums) {
        int reachable=0;
        int step=0;
        int current=0;
        for(int i=0;i<nums.size();i++)
        {
            if(reachable<i)
            {
                return -1;
            }
            reachable=max(reachable,i+nums[i]);
            if(i==current and i!=nums.size()-1)
            {
                current=reachable;
                step++;
            }
        }
        return step;
    }
};