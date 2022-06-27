class Solution:
    def minPartitions(self, n: str) -> int:
        ans=0;
        for i in n:
            ans=max(ans,int(i))
        return ans
        