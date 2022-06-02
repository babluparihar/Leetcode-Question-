class Solution:
    def transpose(self, vec: List[List[int]]) -> List[List[int]]:
        ans=[];
        for i in range(0,len(vec[0])):
            v=[]
            for j in range (0,len(vec)):
                v.append(vec[j][i]);         
            ans.append(v);
        return ans;
        