class Solution {
public:

    string discountPrices(string s, int d) {
      int n=s.size();
        //vector to store number
        vector<long double>v;
        //vector to store indcies
        vector<int> idx;
        bool f=false;
        for(int i=0;i<n;i++)
        {
            //bool to check if we actually found a number after $ sign
            f=false;
            //if we encounter dollar sign we will check if the previous 
            //character was either an empty space of start of the string
            if(s[i]=='$' and (i==0 or (s[i-1]==' ')))
            {
                //moving to next index of $ sign
                i++;
                //storing the starting sign
                idx.push_back(i);
                //ans which we will calculate
                long long int ans=0;
                while(i<n and s[i]-'0'>=0 and s[i]-'0'<=9)
                {
                    ans*=10;
                    ans+=s[i]-'0';
                    i++;
                    f=true;
                }
                //we will check if after the number there is a white space or not
                //if theres a white space or we reacher the end or the string we 
                //will push it to our answer else skip it and pop the staring index 
                //as we didnt found a valid number
                if(i==n or (s[i]==' ') and f)
                {
                    //pushing ending index and number
                    idx.push_back(i-1);
                    v.push_back(ans);
                    continue;
                }
                idx.pop_back();
            }
        }
        //this loop will calculate the updated prices after discount
        for(int i=0;i<v.size();i++)
        {
            v[i]=v[i]*(100-d)/100;
        }
        int j=0;
        //resultant string
        string res="";
        for(int i=0;i<n;i++)
        {
            //if j has not reached the end of idx array and i pointer
            //is equal to index stored in idx vector means we should add
            // the number now
            if(j<idx.size() and (i==idx[j]))
            {
                //t is the index of that number in v vector
                int t=j/2,a=0;
                //converting it to string
                string ss=to_string(v[t]);
                //finding '.'
                for(int i=0;i<ss.length();i++)
                {if(ss[i]=='.')
                    {a=i;break;}}
                //making a substring after to places of '.' for eg.
                //ss=0.500000 then temp would be 0.50 
                string temp=ss.substr(0,a+3);
                //adding this string to answer string
                res+=temp;
                //updating i to the last index of number in original array
                //9 in case of example shown above
                i=idx[j+1];
                //taking j to next starting index of a number is exist
                j+=2;
            }
            //if i!=the index of idx vector we will directly add that charcter
            //final string
            else
            {
                res+=s[i];
            }
        }
        //returning the string
        return res;
    }
};