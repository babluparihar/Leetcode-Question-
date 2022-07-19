class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>m;
        for(auto i:paths)
        {
            m[i[0]]=i[1];
        }
        for(auto i:paths)
        {
            if(m.find(i[1])==m.end())
            {
                return i[1];
            }
        }
        return "STRANGER THINGS";
    }
};