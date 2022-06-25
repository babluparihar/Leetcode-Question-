class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count=0;
        for(auto i:words)
        {
            if(i.size()<=s.size() and s.substr(0,min(s.size(),i.size()))==i.substr(0,min(s.size(),i.size())))
            {
                count++;
            }
        }
        return count;
    }
};