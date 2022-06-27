class Solution {
public:
    string findLongestWord(string s, vector<string>& ele) {
        vector<string>ans;
        for(int ii=0;ii<ele.size();ii++)
        {
            string temp=ele[ii];
            if(temp.size()<=s.size())
            {
                int i=0;
                int j=0;
                while(i<s.size())
                {
                    if(s[i]==temp[j])
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        i++;
                    }
                    if(j==temp.size())
                    {
                        break;
                    }
                }
                if(j==temp.size())
                {
                  ans.push_back(ele[ii]);
                }
            }
        }
        if(ans.size()==0)
        {
            return {};
        }
        sort(ans.begin(),ans.end(),[&](const string &a,const string &b){ if(a.size()==b.size()){return a<b;}else{return a.size()>b.size();}});
        return ans[0];
    }
};