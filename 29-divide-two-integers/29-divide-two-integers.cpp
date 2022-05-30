class Solution {
public:
    int divide(int A, int B) {  
        // this problem can be solved using the bit manipulation technique and 
        // we just need to shif the operator and there is the some corner casese where we have to handle them and need to return the answers in  that format also 
        
        // so how we are approaching using the bit manipulation lets see her
        // lets take example of 15 and 3
        
        // 15-3>0  left shift it will get 6 15-6>0 left shift one more time 15-12>0 ONE  more time shftig will be required 15-24<0 so what we are going to do is that 15=3*4=15-12=3 now apply on qutioned
        
        
        if(A==INT_MIN and B==-1)
        {
            return INT_MAX;
        }
    
        int sign=1;
        if((A<0 and B>0) or (A>0 and B<0))
        {
            sign=-1;
        }
    long long   int ans=0;
        long long int AA=labs(A);
        long long int BB=labs(B);
        while(AA>=BB)
        {
            long long temp=BB;
            long long m=1;
            while(temp<<1 <=AA)
            {
                temp<<=1;
                m<<=1;
            }
            AA-=temp;
            ans+=m;
        }
        return  ans*sign;
    }
};