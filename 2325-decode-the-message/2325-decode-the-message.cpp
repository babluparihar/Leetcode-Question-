class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int>vec(26,0);
        string s="";
        for(auto i:key)
        {
            if(i!=' ' and vec[i-'a']==0)
            {
                s+=i;
                vec[i-'a']=1;
            }
        }
        string  ans="";
        for(auto i:message)
        {
            if(i!=' ')
            {
                for(int j=0;j<s.size();j++)
                {
                    if(s[j]==i)
                    {
                      ans+=('a'+j);
                      break;
                    }
                }
            }
            else
            {
                ans+=i;
            }
        }
        return ans;
    }
};