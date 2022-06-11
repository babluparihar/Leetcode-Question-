class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a=count(nums.begin(),nums.end(),1);
        if(a==nums.size())
        {
            return a-1;
        }
        vector<int>one;
        int o=0,z=0;
        for(auto i:nums)
        {
            if(i==1)
            {
                if(z==1)
                {
                    one.push_back(0);
                }
                else if(z>2)
                {
                    one.push_back(INT_MIN);
                }
                z=0;
                o++;
            }
            else if(i==0)
            {
                if(o>0)
                {
                    one.push_back(o);
                }
                o=0;
                z++;
            }
        }

        if(o!=0)
        {
            one.push_back(o);
        }
        // for(auto i:one)
        // {
        //     cout<<i<<" ";
        // }
        if(one.size()==0)
        {
            return 0;
        }
        int ans=0;
        if(one.size()<=2)
        {
            if(one.size()==1)
            {
                return one[0];
            }
            if(one.size()==2)
            {
                 return max(one[0],one[1]);
            }
        }
        for(int i=1;i<one.size()-1;i++)
        {
            if(one[i]==0)
            {
                ans=max(ans,one[i-1]+one[i+1]);
            }
            ans=max(ans,one[i]);
        }
        return ans;
    }
};