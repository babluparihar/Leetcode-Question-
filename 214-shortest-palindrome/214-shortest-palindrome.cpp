class Solution {
public:
    string shortestPalindrome(string s) {
        // this is not working for higher limit test cases
        // string t=s;
        // reverse(t.begin(),t.end());
        // for(int i=0;i<t.size();i++)
        // {
        //     if(t.substr(i)==s.substr(0,s.size()-i))
        //     {
        //         return t.substr(0,i)+s;
        //     }
        // }
        // return t+s;  
         string t = s;
    
    reverse(t.begin(),t.end());

    string p = s + "#"+ t;
    
    int i, j, n = p.size();
    
    vector<int> lps(n,0);
    
    for(i=1; i<n; i++)
    {
        j = lps[i-1];
        
        while(j> 0 && p[i] != p[j])
        {
            j = lps[j-1];
        }
        
        if(p[i] == p[j])
        {
            lps[i] = j+1;
        }
    }
    
    
    string res = t.substr(0, s.size()-lps[n-1]);
    
    return res + s;
    }
};