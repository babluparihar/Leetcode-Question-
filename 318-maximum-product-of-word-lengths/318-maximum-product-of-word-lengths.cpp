class Solution {
public:
    int maxProduct(vector<string>& words) {
           int ans=0;
        for(int i=0;i<words.size();i++)

        {
            string s=words[i];
            unordered_map<char,int>m;
            for(auto j:s)
            {
                m[j]++;
            }
            for(int j=i+1;j<words.size();j++)
            {
                string temp=words[j];
                bool flag=true;
                for(auto x:temp)
                {
                    if(m.find(x)!=m.end())
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag==true)
                {
                    int a=s.size();
                    int b=temp.size();
                    ans=max(ans,a*b);
                }
            }
        }
        return ans;
    }
};