class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        priority_queue<int>q;
        for(int i=1;i<nums.size();i++)
        {
            int diff=nums[i]-nums[i-1];
            if(diff>0)
            {
                q.push(diff);
                bricks-=diff;
                if(bricks<0)
                {
                    if(ladders<=0)
                    {
                        return i-1;
                    }
                    ladders--;
                    bricks+=q.top();
                    q.pop();
                }
            }
        }
        return nums.size()-1;
    }
};