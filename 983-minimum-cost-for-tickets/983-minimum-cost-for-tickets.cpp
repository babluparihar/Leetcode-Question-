class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&days,vector<int>&cost,int ind)
    {
        if(ind>=days.size())
        {
            return 0; 
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        // lest esacpe days and go that way
        
        // for the  first day
        int a=cost[0]+solve(days,cost,ind+1);
        
        // go for the week
        int day=days[ind];
        day+=7;
        int i;
        for( i=ind;i<days.size() and days[i]<day; i++);
        int b=cost[1]+solve(days,cost,i);
        
        // now go for the month
        int month=days[ind]+30;
        for( i=ind;i<days.size() and days[i]<month;i++);
        int c=cost[2]+solve(days,cost,i);
        
        return dp[ind]=min({a,b,c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size()+1,-1);
        return solve(days,costs,0);
    }
};