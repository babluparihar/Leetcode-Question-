class Solution {
public:
    vector<long long>v;
     int fun(vector<long long>c,int a)
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
                    sub_res=fun(c,a-c[i]);
                }
            if(sub_res!=INT_MAX and sub_res+1<res)
            {
                res=sub_res+1;
            }
                
            }
        }
        return v[a]=res;
        
    }
    int numSquares(int n) {
        int x=sqrt(n);
        vector<long long>vec;
        for(int i=1;i<=x;i++)
        {
            vec.push_back(i*i);
        }
        v.resize(n+1,-1);
        return fun(vec,n);
    }
};