class Solution {
public:

    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long  a=total/cost1;
        long long  b=total/cost2;
        long long  ans=0;
        for(long long i=0;i<=a;i++)
        {
            if(i==0)
            {
                ans+=(b+1);
            }
            else
            {
                long long left_money=total-i*cost1;
                if(left_money>0)
                {
                   ans+=(left_money/cost2)+1;
                }
                else
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};