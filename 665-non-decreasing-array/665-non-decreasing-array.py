class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if(len(nums)<=2):
            return True
        past1=nums[0]
        past2=-1e5-1;
        count=0
        for i in range(1,len(nums)):
            if(past1>nums[i]):
                if(i+1==len(nums) and count==0):
                    return True
                elif(i+1<len(nums) and past1<=nums[i+1]):
                    past2=past1
                    past1=nums[i+1]
                    count+=1
                elif(past2<=nums[i]):
                    count+=1
                    past1=nums[i]
                else:
                    return 0
            else:
                past2=past1
                past1=nums[i]
        return count<=1