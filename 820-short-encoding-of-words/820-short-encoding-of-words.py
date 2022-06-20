class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        t={};
        ans=0
        words.sort(key=len,reverse=True)
        for s in words:
            if(t.get(s)):
                continue;
            else:
                for i in range (0,len(s)):
                    t[s[i:len(s)]]=1;
                ans+=(len(s)+1);
        return ans;
        