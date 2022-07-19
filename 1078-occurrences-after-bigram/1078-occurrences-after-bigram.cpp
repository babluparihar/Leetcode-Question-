class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string>vec;
        vector<string>v;
        string t="";
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==' ')
            {
                v.push_back(t);
                t="";
            }
            else
            {
                t+=text[i];
            }
        }
        v.push_back(t);
        for(int i=1;i<v.size()-1;i++)
        {
            if(first==v[i-1] and  second==v[i] )
            {
                vec.push_back(v[i+1]);
            }
        }
        return vec;
    }
};