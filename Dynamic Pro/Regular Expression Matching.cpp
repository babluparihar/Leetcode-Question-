Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
  
  
  class Solution {
public:
    
    // this is the backtracking kind of solution :)
    bool match(string &s,string &p,int i,int j)
    {
        if(i>=s.size() and j>=p.size())
        {
            return true;
        }
        if(j>=p.size())
        {
            return false;
        }
        bool mtch=(i<s.size() and (s[i]==p[j] or p[j]=='.'));
        if(j+1<p.size() and p[j+1]=='*')
        {
          return (mtch==true and match(s,p,i+1,j))  or match(s,p,i,j+2);
        }
        if(mtch==true)
        {
            return match(s,p,i+1,j+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return match(s,p,0,0);
    }
};
