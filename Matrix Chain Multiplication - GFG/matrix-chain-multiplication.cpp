// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<vector<int>>m;
int mcm(int arr[],int i,int j)
{
    if(i>=j)
    {
        return m[i][j]=0;
    }
    if(m[i][j]!=-1)
    {
        return m[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        ans=min(ans,arr[i-1]*arr[k]*arr[j]+mcm(arr,i,k)+mcm(arr,k+1,j));
    }
    return m[i][j]=ans;
}
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        m.resize(N+1,vector<int>(N,-1));
        return mcm(arr,1,N-1);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends