class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int>m;
        int z=count(arr.begin(),arr.end(),0);
        if(z%2!=0)   // because z canit be mapped with other than it self
        {
            return false;
        }
        for(auto i:arr)
        {
            m[i]++;
        }
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i];
            if(m.find(x)!=m.end() and m.find(2*x)!=m.end())
            {
                count++;
                m[x]--;
                m[2*x]--;
                if(m[x]==0)
                {
                    m.erase(x);
                }
                if(m[2*x]==0)
                {
                    m.erase(2*x);
                }
            }
        }
        return count==arr.size()/2;
    }
};