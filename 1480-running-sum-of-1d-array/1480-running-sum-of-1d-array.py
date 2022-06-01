class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        vec=[];
        sum=0;
        for i in nums:
            sum+=i;
            vec.append(sum)
        return vec