class Solution {
public:
    static bool comp(const vector<int>&first,const vector<int>&second)
    {
        if(first[0]==second[0])
        {
            return first[1]>second[1];
        }
        return first[0]<second[0];
    }
    int maxEnvelopes(vector<vector<int>>& vec) {
        // just need to sort and then just need to find the longest increasing subsequence
        sort(vec.begin(),vec.end(),comp);
        vector<int>first;
        for(auto i:vec)
        {
            first.push_back(i[1]);
        }
        // now just find the lis of the give element
        vector<int>second;
        second.push_back(first[0]);
        for(int i=1;i<first.size();i++)
        {
            if(second[second.size()-1]<first[i])
            {
                second.push_back(first[i]);
            }
            else
            {
                auto it=lower_bound(second.begin(),second.end(),first[i]);
                *it=first[i];
            }
        }
        return second.size();
    }
};