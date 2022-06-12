class Solution {
public:
int longestBeautifulSubstring(string word) {
string vowel="aeiou";
int i=0;
int j=0;
int count=0;
int ans=0;
while(j<word.size())
{
if(word[j]==vowel[i])
{
count++;
}
else if(i<4 and word[j]==vowel[i+1] and count!=0 and j>0 and word[j-1]==vowel[i])
{
i++;
count++;
}
else
{
if(word[j]=='a')
{
    count=1;
}
else
{
    count=0;
}
// count=0;
i=0;
}
if(i==4)
{
ans=max(ans,count);
}
j++;
}
if(i==4)
{
ans=max(ans,count);
}
return ans<5?0:ans;
}
};