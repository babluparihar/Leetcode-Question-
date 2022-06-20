class Solution {
public:
    static bool comp(const string &a,const string &b)
    {
        return a.size()>b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        map<string,int>m;
        sort(words.begin(),words.end(),comp);    // sorting to get the big length element first an
        for(int i=0;i<words.size();i++)
        {
            string t=words[i];
            if(m.find(t)!=m.end())
            {
                continue;
            }
            for(int j=0;j<t.size();j++)
            {
                string s=t.substr(j);
                m[s]++;
            }
            ans+=(words[i].size()+1);
        }
        return ans;
    }
};