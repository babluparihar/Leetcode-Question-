class Solution {
public:
    struct Trie
    {
        Trie *child[26];
        bool isend;
        Trie()
        {
            isend=false;
            for(int i=0;i<26;i++)
            {
                child[i]=NULL;
            }
        }
    };
    void insert(Trie *root,string &s)
    {
        Trie *curr=root;
        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            if(curr->child[index]==NULL)
            {
                curr->child[index]=new Trie();
            }
            curr=curr->child[index];
        }
        curr->isend=true;
    }
    vector<string> search(Trie *root,string &pre)
    {
        Trie *curr=root;
        vector<string>vec;
        for(int i=0;i<pre.size();i++)
        {
            int index=pre[i]-'a';
            if(curr->child[index]==NULL)
            {
                return {};
            }
            curr=curr->child[index];
        }
        dfs(curr,pre,vec);
        return vec;
    }
    void dfs(Trie *root,string pre,vector<string>&vec)
    {
        if(vec.size()==3)
        {
            return ;
        }
        if(root->isend==true)
        {
            vec.push_back(pre);
        }
        for(int i=0;i<26;i++)
        {
            if(root->child[i]!=NULL)
            {
                dfs(root->child[i],pre+char((i+'a')),vec);
            }
        }
    }
 
    vector<vector<string>> suggestedProducts(vector<string>& p, string w) {
        Trie *root=new Trie();
        for(auto i:p)
        {
            insert(root,i);
        }
        vector<vector<string>>ans;
        string pre="";
        for(int i=0;i<w.size();i++)
        {
            pre+=w[i];
            vector<string>v=search(root,pre);
            // if(v.size()!=0)
            // {
                ans.push_back(v);
            // }
        }
        return ans;
    }
};