class Solution {
public:
    vector<long long> maximumEvenSplit(long long s) {
        if(s%2!=0)

        {
            return {};
        }
        else
        {
            vector<long long>vec;
            long long sum=0;
            for(long long i=2;i<=s;i+=2)
            {
                sum+=i;
                long long tem=s-sum;
                
                if(tem<=i)
                {
                    vec.push_back(i+tem);
                    return vec;
                }
                else
                {
                    vec.push_back(i);
                }
                if(sum==s)
                {
                    return vec;
                }
            }
            
            return vec;
        }
    }
};