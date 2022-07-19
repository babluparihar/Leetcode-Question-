class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size()<=k)
        {
            return s;
        }
        while(true)
        {
            string temp="";
            int t=k;
            int i=0;
            while(i<s.size())
            {
                int sum=0;
                for(int j=i;j<s.size() and j<t;j++)
                {
                    sum+=(s[j]-'0');
                    i++;
                }
                t+=k;
                temp+=to_string(sum);
            }
            s=temp;
            if(s.size()<=k)
            {
                return s;
            }
        }
        return s;
    }
};