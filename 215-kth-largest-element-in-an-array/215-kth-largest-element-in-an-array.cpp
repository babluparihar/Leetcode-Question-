class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto i:nums)
        {
            q.push(i);
        }
        for(int i=0;i<k-1;i++)
        {
            q.pop();
        }
        return q.top();
    }
};