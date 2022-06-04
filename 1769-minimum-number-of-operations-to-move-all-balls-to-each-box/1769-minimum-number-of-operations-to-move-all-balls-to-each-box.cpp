class Solution {
public:
vector<int> minOperations(string s) {
vector<int>ans;
for(int i=0;i<s.size();i++)
{
int count=0;
for(int j=0;j<i;j++)
{
if(s[j]=='1')
{
count+=(i-j);

}
}
for(int j=i+1;j<s.size();j++)
{
if(s[j]=='1')
{
count+=(j-i);
}

}
ans.push_back(count);
}
return ans;
}
};