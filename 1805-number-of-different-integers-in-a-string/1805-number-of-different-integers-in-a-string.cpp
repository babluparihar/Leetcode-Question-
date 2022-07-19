class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_map<string,int>m;
        for(int i=0;i<word.size();i++)
        {
            if((word[i]-'0')>=0 and (word[i]-'0')<=9)
            {
                string t="";
                while(i<word.size() and ((word[i]-'0')>=0 and (word[i]-'0')<=9))
                {
                    t+=word[i];
                    i++;
                }
                string tt="";
                int j=0;
                while(j<t.size() and t[j]=='0')
                {
                    j++;
                }
                tt=t.substr(j);
                // cout<<tt<<endl;
                m[tt]++;
                if(i==word.size())
                {
                    return m.size();
                }
                i--;
            }
        }
        return m.size();
    }
};