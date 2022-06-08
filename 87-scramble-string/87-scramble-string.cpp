class Solution {
public:
    map<string,bool>m;
     bool solve(string a,string b)
     {
         if(a.size()!=b.size())
         {
             return false;
         }
         int n=a.size();
         if(n==0)
         {
             return true;
         }
         string s=a;
         string t=b;
         sort(s.begin(),s.end());
         sort(t.begin(),t.end());
         if(a==b)
         {
             return true;
         }
         if(s!=t)
         {
             return false;
         }
         string key=a+"--"+b;
         if(m.find(key)!=m.end())
         {
             return m[key];
         }
         bool flag=false;
         for(int i=1;i<n;i++)
         {
             // two case for the first input 
             bool comp1=solve(a.substr(0,i),b.substr(n-i,i));
             bool comp2=solve(a.substr(0,i),b.substr(0,i));
             bool comp3=solve(a.substr(i,n-i),b.substr(0,n-i));
             bool comp4=solve(a.substr(i,n-i),b.substr(i,n-i));
             if((comp1 and comp3) or (comp2 and comp4))
             {
                 flag=true;
                 break;
             }
         }
         return m[key]=flag;
     }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};