class Solution {
public:
    // static bool comp(const string &a,const string &b)
    // {
    //     return a.size()>b.size();
    // }
    // int minimumLengthEncoding(vector<string>& words) {
    //     int ans=0;
    //     unordered_map<string,int>m;
    //     sort(words.begin(),words.end(),comp);    // sorting to get the big length element first an
    //     for(int i=0;i<words.size();i++)
    //     {
    //         string t=words[i];
    //         if(m.find(t)!=m.end())
    //         {
    //             continue;
    //         }
    //         for(int j=0;j<t.size();j++)
    //         {
    //             string s=t.substr(j);
    //             m[s]++;
    //         }
    //         ans+=(words[i].size()+1);
    //     }
    //     return ans;
    // }
    struct trie{
        bool isend;
        trie *child[26];
        trie()
        {
            isend=false;
            for(int i=0;i<26;i++)
            {
                child[i]=NULL;
            }
        }
    };
    void insert(trie *root,string s)
    {
        for(auto i:s)
        {
            int ind=i-'a';
            if(root->child[ind]==NULL)
            {
                root->child[ind]=new trie();
            }
            root=root->child[ind];
        }
        root->isend=true;
    }
    bool search(trie *root,string s)
    {
        for(auto i:s)
        {
            int ind=i-'a';
            if(root->child[ind]==NULL)
            {
                return false;
            }
            root=root->child[ind];
        }
        return true;
    }
        int minimumLengthEncoding(vector<string>& words) {
            trie *root=new trie();
            int ans=0;
            sort(words.begin(),words.end(),[&](const string &a,const string &b){return a.size()>b.size();});
            for(int i=0;i<words.size();i++)
            {
                string s=words[i];
                reverse(s.begin(),s.end());
                if(search(root,s)==true)
                {
                    continue;
                }
                else
                {
                    insert(root,s);
                    ans+=s.size()+1;
                }
            }
            return ans;
            
        }
};