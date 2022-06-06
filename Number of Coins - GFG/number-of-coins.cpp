// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
vector<int>dp;
int fun(int coins[],int M,int V)
{
        if(V==0)
        {
         return 0;
        }
        if(dp[V]!=-1)
        {
         return dp[V];
        }
int res=INT_MAX;
for(int i=0;i<M;i++)
{
if(coins[i]<=V)
{
 int sub_res=fun(coins,M,V-coins[i]);
if(sub_res!=INT_MAX and sub_res+1<res)
{
 res=sub_res+1;
}
}
}
return dp[V]=res;
}

int minCoins(int coins[], int M, int V) 
{
dp.resize(V+1,-1);
int ans=fun(coins,M,V);
if(ans==INT_MAX)
{
return -1;
}
return ans;
} 

};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends