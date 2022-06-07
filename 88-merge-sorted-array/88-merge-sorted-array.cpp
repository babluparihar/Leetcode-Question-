class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // priority_queue<int,vector<int>,greater<int>>q;
        // for(auto i:nums2)
        // {
        //     q.push(i);
        // }
        // int i=0;
        // for( i=0;i<m;i++)
        // {
        //     if(q.size()!=0 and nums1[i]<=q.top())
        //     {
        //     }
        //     else if(q.size()!=0)
        //     {
        //         int temp=nums1[i];
        //         nums1[i]=q.top();
        //         q.pop();
        //         q.push(temp);
        //     }
        // }
        // while(q.size()!=0 and i<nums1.size())
        // {
        //     nums1[i]=q.top();
        //     q.pop();
        //     i++;
        // }
        int i=m-1;
        int j=n-1;
        for(int k=nums1.size()-1;k>=0;k--)
        {
            if(i>=0 and j>=0  and nums1[i]>=nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
            }
            else if(j>=0)
            {
                nums1[k]=nums2[j];
                j--;
            }
        }
    }
};