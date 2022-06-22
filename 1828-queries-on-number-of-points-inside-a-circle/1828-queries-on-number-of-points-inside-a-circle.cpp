class Solution {
public:
    bool valid(int x1,int y1,int x2,int y2,int r)
    {
        int a=x1-x2;
        int b=y1-y2;
        if(a*a+b*b<=r*r)
        {
            return true;
        }
        return false;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto i:queries)
        {
            int x=i[0];
            int y=i[1];
            int r=i[2];
            int count=0;
            for(int i=0;i<points.size();i++)
            {
                if(valid(x,y,points[i][0],points[i][1],r))
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
    
};