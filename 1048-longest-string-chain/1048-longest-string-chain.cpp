class Solution {
public:
    // bool valid(string a,string b)
    // {
    //     if(a.size()-b.size()!=1)
    //     {
    //         return false;
    //     }
    //     int j=0;
    //     int c=0;
    //     for(int i=0;i<a.size();i++)
    //     {
    //         if(a[i]!=b[j])
    //         {
    //             c++;
    //         }
    //         else if(j<b.size() and a[i]==b[j])
    //         {
    //             j++;
    //         }
    //     }
    //     return c<=1;
    // }
    // int solve(vector<string>&vec,int i,string s)
    // {
    //     if(i>=vec.size())
    //     {
    //         return 0;
    //     }
    //     // if(m.find(s)!=m.end())
    //     // {
    //     //     return m[s];
    //     // }
    //     if(valid(vec[i],s))
    //     {
    //         return max(1+solve(vec,i+1,vec[i]),solve(vec,i+1,s));
    //     }
    //     else
    //     {
    //         return max(solve(vec,i+1,vec[i]),solve(vec,i+1,s));
    //     }
    // }
    static bool comp(const string &a,const string &b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int>m;
        int ans=1;
        for(auto s:words)
        {
            m[s]=1;
            for(int i=0;i<s.size();i++)
            {
                string f=s.substr(0,i)+s.substr(i+1);
                if(m.find(f)!=m.end())
                {
                    m[s]=m[f]+1;
                    ans=max(ans,m[s]);
                }
            }
        }
        return ans;
    }
};