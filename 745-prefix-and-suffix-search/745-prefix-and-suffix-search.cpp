class WordFilter {
    private:
    unordered_map<string,int>m;
public:
    
    WordFilter(vector<string>& s) {
        for(int i=0;i<s.size();i++)
        {
            // we have to store all prefix and suffix of a string
            for(int j=1;j<=s[i].size();j++)
            {
                string pre=s[i].substr(0,j);
                for(int k=0;k<s[i].size();k++)
                {
                    string suff=s[i].substr(k,s[i].size());
                    m[pre+"|"+suff]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string key=prefix+"|"+suffix;
        if(m.find(key)==m.end())
        {
            return -1;
        }
        return m[key]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */