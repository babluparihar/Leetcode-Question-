// class Solution {
// public:
//     // 3d dp
//     long long int dp[100002][2];
//     long long int mod=1e9+7;
//     long long int solve(vector<int>&nums1,vector<int>&nums2,map<long long int,vector<long long int>>&m,int i,int flag)
//     {
//         if(flag==0 and i>=nums1.size()){return 0;}
//         if(flag==1 and i>=nums2.size()){return 0;}
//         if(dp[i][flag]!=-1)
//         {
//             return dp[i][flag];
//         }
//         if(flag==0)  //  go for both element
//         {
//             if(m[nums1[i]].size()==2)
//             {
//                  int a=nums1[i]+solve(nums1,nums2,m,i+1,0);
//                  int b=nums1[i]+solve(nums1,nums2,m,m[nums1[i]][1],1);
//                  dp[i][flag]=max(a,b);
//             }
//             else
//             {
//                  dp[i][flag]=(long long int)nums1[i]+solve(nums1,nums2,m,i+1,flag);
//             }
//         }
//         else
//         {
//              if(m[nums2[i]].size()==2)
//             {
//                  int a=nums2[i]+solve(nums1,nums2,m,i+1,1);
//                  int b=nums2[i]+solve(nums1,nums2,m,m[nums2[i]][0],0);
//                  dp[i][flag]=max(a,b);
//             }
//             else
//             {
//                  dp[i][flag]=(long long int)nums2[i]+solve(nums1,nums2,m,i+1,flag);
//             }
//         }
//         return dp[i][flag]%mod;
//     }
//     int maxSum(vector<int>& nums1, vector<int>& nums2) {
//         map<long long int,vector<long long int>>m;
//         memset(dp,-1,sizeof(dp));
//         for(int i=0;i<nums1.size();i++)
//         {
//             m[nums1[i]].push_back(i+1);
//         }
//         for(int i=0;i<nums2.size();i++)
//         {
//             m[nums2[i]].push_back(i+1);
//         }
//         long long int ans=max(solve(nums1,nums2,m,0,0),solve(nums1,nums2,m,0,1));
//         return ans;
//     }
// };


class Solution {
public:
    map<int, int> mp1, mp2;
    int n, m;
    vector<int> nums1,nums2;
    
    long long int dp[100002][2];
    int mod =1e9+7;
    
    long long int solve(int i, int c){
        if(c==0 && i>=n) return 0;
        if(c==1 && i>=m) return 0;
        
        if(dp[i][c]!=-1) return dp[i][c];
        
        if(c){
            if(mp1[nums2[i]]){
                dp[i][c]=max(nums2[i]+solve(mp1[nums2[i]],c^1), nums2[i]+solve(i+1,c));
            }
            else {dp[i][c]=(long long int)nums2[i]+solve(i+1,c); }
        }
        
        else{
            if( mp2[nums1[i]]){
                dp[i][c]=max(nums1[i]+solve(mp2[nums1[i]],c^1), nums1[i]+solve(i+1,c));
            }
            else {dp[i][c]=(long long int)nums1[i]+solve(i+1,c);}
        }
        return dp[i][c];
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        this->nums1 = nums1;
        this->nums2 = nums2;
        memset(dp,-1,sizeof dp);
        
        for(int i=0;i<n;i++){
            mp1[nums1[i]] = i+1;
        }
        for(int i=0;i<m;i++){
            mp2[nums2[i]]=i+1;
        }
        
        long long int ans=max(solve(0,0), solve(0,1));
        
        return ans%mod;
    }
};