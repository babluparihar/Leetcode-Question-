class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // generate all the binary string and then return the any of them
        vector<string>vec;
        vec.push_back("0");
        vec.push_back("1");
        int k=nums[0].size();
        while(vec[0].size()!=k)
        {
            vector<string>temp(vec);
            vec.clear();
            for(auto i:temp)
            {
                vec.push_back("1"+i);
            }
            for(auto i:temp)
            {
                vec.push_back("0"+i);
            }
        }
        unordered_map<string,int>m;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(int i=0;i<vec.size();i++)
        {
            if(m[vec[i]]==0)
            {
                return vec[i];
            }
        }
        return "";
    }
};