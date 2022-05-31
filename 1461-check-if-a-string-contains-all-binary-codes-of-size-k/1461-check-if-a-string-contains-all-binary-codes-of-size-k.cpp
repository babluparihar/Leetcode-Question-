class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<pow(2,k))
        {
            return false;
        }
        vector<string>vec;
        vec.push_back("0");
        vec.push_back("1");
        for(int i=1;i<k;i++)
        {
            vector<string>first(vec);
            vec.clear();
            for(auto i:first)
            {
                string s="1"+i;
                vec.push_back(s);
            }
              for(auto i:first)
            {
                string s="0"+i;
                vec.push_back(s);
            }
        }
        unordered_map<string,int>m;
        for(auto i:vec)
        {
            m[i]++;
        }
        unordered_map<string,int>mm;
        int count=0;
        for(int i=0;i<=s.size()-k;i++)
        {
            string sss=s.substr(i,k);
            // cout<<sss<<endl;
            if(m.find(sss)!=m.end())
            {
                 mm[sss]++;
            }
        }
        return mm.size()==m.size();
        
        }
};