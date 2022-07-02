class Solution {
public:
    int maxArea(int h, int w, vector<int>&hh, vector<int>& vv) {
        int mx1=0;
        int mx2=0;
        sort(hh.begin(),hh.end());
        sort(vv.begin(),vv.end());
        int trail=0;
        for(int i=0;i<hh.size();i++)
        {
            mx1=max(mx1,hh[i]-trail);
            trail=hh[i];
        }
        mx1=max(mx1,h-trail);
        trail=0;
        for(auto i:vv)
        {
            mx2=max(mx2,i-trail);
            trail=i;
        }
        mx2=max(mx2,w-trail);
        if(mx1==0)
        {
            mx1=h;
        }
        if(mx2==0)
        {
            mx2=w;
        }
        long long int mod=1e9+7;
        long long int ans=((mx1%mod)*(mx2%mod))%mod;
        return ans;
    }
};