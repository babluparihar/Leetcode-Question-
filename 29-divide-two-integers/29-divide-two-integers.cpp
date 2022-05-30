class Solution {
public:
    int divide(int A, int B) {
        long long int a=pow(2,31)-1;
        long long int b=-pow(2,31);             
        long long x=A;
        long long y=B;
        long long ans=x/y;
        if(ans>a)
        {
          return a;
        }
        if(ans<b)
        {
            return b;
        }
        return ans;
      
        
    }
};