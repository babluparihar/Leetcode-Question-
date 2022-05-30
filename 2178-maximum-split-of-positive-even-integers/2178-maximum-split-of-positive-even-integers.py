class Solution:
    def maximumEvenSplit(self, s: int) -> List[int]:
        if(s%2!=0):
            return {};
        else:
            vec=[];
            sum=0;
            for i in range (2,s+1,2):
                sum+=i;
                temp=s-sum;
                if(temp<=i):
                    vec.append(i+temp);
                    return vec;
                else:
                    vec.append(i);
                if(sum==s):
                    return vec;
        return vec;
        