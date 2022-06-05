class Solution {
public:
    int minMaxGame(vector<int>& v) {
        if(v.size()==1)
        {
            return v[0];
        }
        vector<int>nums(v);
        while(true)
        {
            vector<int>vec;
            int n=nums.size();
            for(int i=0;i<n/2;i++)
            {
                if(i%2==0)
                {
                    vec.push_back(min(nums[2*i],nums[2*i+1]));
                }
                else
                {
                    vec.push_back(max(nums[2*i],nums[2*i+1]));
                }
            }
            if(vec.size()==1)
            {
                return vec[0];
            }
            nums.clear();
            for(auto i:vec)
            {
                nums.push_back(i);
            }
        }
        return 0;
    }
};