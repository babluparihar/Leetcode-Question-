class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int ans=0;
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >q;
        for(auto i:courses)
        {
            int x=i[1];
            int y=i[0];
            q.push({x,y});
        }
        int course_end=0;
        int final_ans=0;
        priority_queue<int>pq;
        while(!q.empty())
        {
            course_end+=q.top().second;
            pq.push(q.top().second);
            final_ans++;
            if(course_end>q.top().first)
            {
                final_ans--;
                course_end-=pq.top();
                pq.pop();
            }
            q.pop();
        }
        return final_ans;
    }
};