class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int len=0;
        int i=0;
        int j=0;
        while(j<s.size())
        {
            m[s[j]]++;
            if(m[s[j]]==1)
            {
                
            }
            else
            {
                while(i<s.size() and i<j and s[i]!=s[j])
                {
                    m[s[i]]--;
                    i++;
                }
                m[s[i]]--;
                i++;
            }
            j++;
            len=max(len,j-i);
        }
        return len;
    }
};