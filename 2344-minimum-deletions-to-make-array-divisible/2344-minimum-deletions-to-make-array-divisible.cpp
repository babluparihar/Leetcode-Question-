class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& vec) {
        // In mathematics, the greatest common divisor (GCD) of two or more integers, which are not all zero, is the largest positive integer that divides each of the integers. For two integers x, y, the greatest common divisor of x and y is denoted {\displaystyle \gcd(x,y)}{\displaystyle \gcd(x,y)}. For example, the GCD of 8 and 12 is 4, that is, {\displaystyle \gcd(8,12)=4}{\displaystyle \gcd(8,12)=4}.[1][2]
        
        
        int gcd=vec[0];
        for(int i=1;i<vec.size();i++)
        {
            gcd=__gcd(gcd,vec[i]);
        }
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(gcd%nums[i]==0)
            {
                return i;
            }
            else if(nums[i]>gcd)
            {
                return -1;
            }
        }
        return -1;
    }
};