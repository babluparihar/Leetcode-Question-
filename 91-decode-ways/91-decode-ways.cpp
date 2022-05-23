class Solution {
public:
    int numDecodings(string s) {
        vector<int>count(s.size()+1,0);
        if(s[0]=='0')
        {
            return 0;
        }
        count[0]=1;
        for(int i=1;i<=s.size();i++)
        {
            if(s[i-1]>'0')
            {
                count[i]=count[i-1];
            }
            if(i>=2 and (s[i-2]=='1' or (s[i-2]=='2' and s[i-1]<'7')))
            {
                count[i]+=count[i-2];
            }
        }
        return count[s.size()];
    }
};