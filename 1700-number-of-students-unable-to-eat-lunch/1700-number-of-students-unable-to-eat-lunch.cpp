class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q;
        stack<int>s;
        for(auto i:students)
        {
            q.push(i);
        }
        for(int i=sandwiches.size()-1;i>=0;i--)
        {
            s.push(sandwiches[i]);
        }
        int swap=0;
        while(q.size()!=0)
        {
            if(q.front()==s.top())
            {
                swap=0;
                s.pop();
                q.pop();
            }
            else
            {
                swap++;
                int x=q.front();
                q.pop();
                q.push(x);
            }
            if(swap>q.size())
            {
                return q.size();
            }
        }
        return 0;
    }
};