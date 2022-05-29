class Solution {
public:
    int maxProduct(vector<string>& words) {
//     this is the way of this brutte force 
        
        //            int ans=0;
//         for(int i=0;i<words.size();i++)

//         {
//             string s=words[i];
//             unordered_map<char,int>m;
//             for(auto j:s)
//             {
//                 m[j]++;
//             }
//             for(int j=i+1;j<words.size();j++)
//             {
//                 string temp=words[j];
//                 bool flag=true;
//                 for(auto x:temp)
//                 {
//                     if(m.find(x)!=m.end())
//                     {
//                         flag=false;
//                         break;
//                     }
//                 }
//                 if(flag==true)
//                 {
//                     int a=s.size();
//                     int b=temp.size();
//                     ans=max(ans,a*b);
//                 }
//             }
//         }
//         return ans;
        
        // using bitmanipultion
        
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            int bit=0;
            string s=words[i];
            for(int j=0;j<s.size();j++)
            {
                int val=s[j]-'a';
                bit|=(1<<val);
            }
            for(int j=i+1;j<words.size();j++)
            {
                bool flag=true;
                for(auto k:words[j])
                {
                    int val=k-'a';
                    int l=bit & (1<<val);
                    if(l>0)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    int a=words[i].size();
                    int b=words[j].size();
                    ans=max(ans,a*b);
                }
            }
        }
        return ans;
    }
};