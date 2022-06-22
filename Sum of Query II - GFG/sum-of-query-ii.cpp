// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>tree;
    vector<int>vec;
    int build(int ss,int se,int si)
    {
        // now 4 cordinates build
        if(ss==se)
        {
            tree[si]=vec[ss];
            return tree[si];
        }
        else
        {
            int mid=(ss+se)/2;
            int left=build(ss,mid,2*si+1);
            int right=build(mid+1,se,2*si+2);
            tree[si]=left+right;
            return tree[si];
        }
    }
    int get_sum(int ss,int se,int qs,int qe,int si)
    {
       // first of all go for the invalid input then go for the all other input
       if(qs>se or qe<ss)
       {
           return 0;
       }
       if(qs<=ss and qe>=se)
       {
           return tree[si];
       }
       int mid=(ss+se)/2;
       int left=get_sum(ss,mid,qs,qe,2*si+1);
       int right=get_sum(mid+1,se,qs,qe,2*si+2);
       return left+right;
    }
    vector<int> querySum(int n, int arr[], int q, int qu[])
    {
        // code here
        // first of all construct the segment tree
        tree.resize(4*n);
        vec.assign(arr,arr+n);
        build(0,n-1,0);
        vector<int>ans;
        for(int i=0;i<2*q;i+=2)
        {
            int qs=qu[i]-1;
            int qe=qu[i+1]-1;
            int value=get_sum(0,n-1,qs,qe,0);
            ans.push_back(value);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends