class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        // if duplicte is not persent than it is impossible to pick up the card
        int i=0;
        int j=0;
        unordered_map<int,int>m;
        int ans=INT_MAX;
        while(j<cards.size())
        {
            m[cards[j]]++;
            if(m[cards[j]]==1)
            {
                
            }
            else
            {
                while(i<cards.size() and i<j and cards[i]!=cards[j])
                {
                    m[cards[i]]--;
                    i++;
                }
                    ans=min(ans,j-i+1);
                m[cards[i]]--;
                i++;
            }
            j++;
        }
        
        return ans==INT_MAX ? -1:ans;
    }
};