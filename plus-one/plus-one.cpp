class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       if(digits[digits.size()-1]<=8)
       {
           digits[digits.size()-1]+=1;
           return digits;
       }
       vector<int>res;
        int rem=0;
        int val=0;
       for(int i=digits.size()-1;i>=0;i--)
       {
           if(i==digits.size()-1)
           {
               val=digits[i];
               val+=1;
               res.push_back(val%10);
               rem=val/10;
           }
           else
           {
               val=digits[i]+rem;
               res.push_back(val%10);
               rem=val/10;
           }
       }
        if(rem!=0)
        {
            res.push_back(rem);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};