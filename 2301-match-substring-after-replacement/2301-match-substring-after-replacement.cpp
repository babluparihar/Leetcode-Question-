class Solution {
public:
    bool check(string a,string &b,unordered_map<char,unordered_set<char>>&m)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                if(m[b[i]].find(a[i])!=m[b[i]].end())
                {
                    
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mp) {
        unordered_map<char,unordered_set<char>>m;
        for(auto i:mp)
        {
            m[i[0]].insert(i[1]);
        }
        if(s.size()<sub.size())
        {
            return false;
        }
        for(int i=0;i<s.size()-sub.size()+1;i++)
        {
            string temp=s.substr(i,sub.size());
            if(check(temp,sub,m)==true)
            {
                return true;
            }
        }   
        
        return false;
    }
};