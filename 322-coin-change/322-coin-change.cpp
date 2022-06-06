class Solution {
public:
    vector<int>v;
    int min_coint(vector<int>c,int a)
    {
        if(a==0)
        {
            return 0;
        }
        if(v[a]!=-1)
        {
            return v[a];
        }
        int res=INT_MAX;
        for(int i=0;i<c.size();i++)
        {
            if(c[i]<=a)
            {
                int sub_res=0;
                if(v[a-c[i]]!=-1)
                {
                    sub_res=v[a-c[i]];
                }
                else
                {
                    sub_res=min_coint(c,a-c[i]);
                }
            if(sub_res!=INT_MAX and sub_res+1<res)
            {
                res=sub_res+1;
            }
                
            }
        }
        return v[a]=res;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        v.resize(amount+1,-1);
        int a =min_coint(coins,amount);
        if(a==INT_MAX)
        {
            return -1;
        }
        return a;
    }
};