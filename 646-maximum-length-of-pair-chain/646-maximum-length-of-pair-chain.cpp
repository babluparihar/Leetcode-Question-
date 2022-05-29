class Solution {
public:
        static bool comp(const vector<int>&first,vector<int>&second)
    {
        return first[1]<second[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int ans=0;
        for(int i=0;i<pairs.size();i++)
        {
            int count=1;
            int last=pairs[i][1];
            for(int j=i+1;j<pairs.size();j++)
            {
                if(last<pairs[j][0])
                {
                    count++;
                    last=pairs[j][1];
                }
            }
            ans=max(ans,count);
        }
        return ans;
    }
};