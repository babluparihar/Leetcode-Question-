// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	     int sum=accumulate(nums,nums+n,0);
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0 and j!=0)
                {
                    dp[i][j]=0;
                }
                else if(i==0 and j==0)
                {
                    dp[i][j]=1;
                }
                else if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]] or dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        for(int i=sum/2;i>=0;i--)
        {
            if(dp[n][i]==true)
            {
                return sum-2*i;
            }
        }
        return 0;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends