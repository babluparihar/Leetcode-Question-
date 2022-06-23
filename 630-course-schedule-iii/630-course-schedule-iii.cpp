class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int>q;
        int values=0;
        for(int i=0;i<courses.size();i++)
        {
            values+=courses[i][0];
            q.push(courses[i][0]);
            if(values>courses[i][1])
            {
                values-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};