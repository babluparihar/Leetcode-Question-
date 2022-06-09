class Solution {
public:
    int countSubstrings(string s, string t) {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<t.size();j++)
            {
                int len=min(s.size()-i,t.size()-j);
                int diff=0;
                for(int k=0;k<len;k++)
                {
                    if(s[i+k]!=t[j+k])
                    {
                        diff++;
                    }
                    if(diff>1)
                    {
                        break;
                    }
                    count+=diff;
                }
            }
        }
        return count;        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         // generate all substring from the t and store in the map and then change a letter and the check if matching or not if matching the answer can be formed otherwise cant be formed
        
//         unordered_map<string,int>m;
//         unordered_map<string,int>check;
//         for(int i=0;i<t.size();i++)
//         {
//             for(int j=0;j<=i;j++)
//             {
//                 string ss=t.substr(j,i-j+1);
//                 m[ss]++;
//             }
//         }
     
//         int count=0;
//         unordered_map<string,int>s_substring;
//          for(int i=0;i<s.size();i++)
//         {
//             for(int j=0;j<=i;j++)
//             {
//                  string ss=s.substr(j,i-j+1);
//                  s_substring[ss]++;
//             }
//         }
//         vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
//         for(auto i:s_substring)
//         {
//                string ss=i.first;
            
//                for(int k=0;k<ss.size();k++)
//                 {
//                     string flag=ss;
//                     for(char c='a';c<='z';c++)
//                     {
//                         if(flag[k]!=c)
//                         {
//                             char prev=flag[k];
//                             flag[k]=c;
//                             if( m[flag]>=1)
//                             {
//                                 count+=m[flag]*i.second;
//                             }
//                             flag[k]=prev;
//                         }
//                     }
//                }
//         }          
//         return count;
    }
};