class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty())
                {
                    if(s[st.top()]=='(')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(i);
                    }
                }
                else
                {
                    st.push(i);
                }
            }
        }
        int ans=0;
        if(st.empty())
        {
            ans=s.size();
        }
        else
        {
            int a=s.size();
            int b=0;
            while(!st.empty())
            {
                b=st.top();
                st.pop();
                ans=max(ans,a-b-1);
                a=b;
            }
            ans=max(ans,a);
        }
        return ans;
    }
};