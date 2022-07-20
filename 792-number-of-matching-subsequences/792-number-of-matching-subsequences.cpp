class Solution {
public:
    // struct trie{
    //     trie *child[26];
    //     bool isend;
    //     trie()
    //     {
    //         isend=false;
    //         for(int i=0;i<26;i++)
    //         {
    //             child[i]=NULL;
    //         }
    //     }
    // };
    // void insert(trie *root,string &s)
    // {
    //     trie *curr=root;
    //     for(int i=0;i<s.size();i++)
    //     {
    //         int ind=s[i]-'a';
    //         if(curr->child[ind]==NULL)
    //         {
    //             curr->child[ind]=new trie();
    //         }
    //         curr=curr->child[ind];
    //     }
    //     curr->isend=true;
    // }
    // bool search(trie *root,string &s,string match)
    // {
    //     trie *curr=root;
    //     int j=0;
    //     for(int i=0;i<s.size();i++)
    //     {
    //         if(s[i]==match[j])
    //         {
    //             j++;
    //         }
    //         curr=curr->child[s[i]-'a'];
    //         if(j>=match.size())
    //         {
    //             return true;
    //         }
    //     }
    //    return j>=match.size();
    // }
    bool search(string &s,string match)
    {
        if(match.size()>s.size())
        {
            return false;
        }
        int i=0;
        int j=0;
        while(j<match.size() and i<s.size())
        {
            if(match[j]==s[i])
            {
                j++;
            }
            i++;
        }
        return j>=match.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>m;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        // trie *root=new trie();
        int ans=0;
        // insert(root,s);
        for(auto i:m)
        {
            if(search(s,i.first))
            {
                ans+=i.second;
            }
        }
        return ans;
    }
};