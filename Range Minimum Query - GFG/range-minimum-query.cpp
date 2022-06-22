// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The functions which 
builds the segment tree */
vector<int>vec;
int build(int ss,int se,int si,int *tree)
{
    if(ss==se)
    {
        tree[si]=vec[ss];
        return tree[si];
    }
    else
    {
        int mid=(ss+se)/2;
        int left=build(ss,mid,2*si+1,tree);
        int right=build(mid+1,se,2*si+2,tree);
        tree[si]=min(left,right);
        return tree[si];
    }
}
int *constructST(int arr[],int n)
{
    int *tree=new int [4*n];
    vec.assign(arr,arr+n);
    build(0,n-1,0,tree);
    return tree;
}

 int get_min(int ss,int se,int qs,int qe,int si,int *tree)
 {
     if(se<qs or qe<ss)
     {
         return INT_MAX;
     }
     // in the range
     if(ss>=qs and qe>=se)
     {
         return tree[si];
     }
     int mid=(ss+se)/2;
     int left=get_min(ss,mid,qs,qe,2*si+1,tree);
     int right=get_min(mid+1,se,qs,qe,2*si+2,tree);
     return min(left,right);
 }

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    return get_min(0,n-1,a,b,0,st);
}