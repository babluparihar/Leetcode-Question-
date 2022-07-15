class Solution {
public:
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // consider this problem as largest histogram And then try to solve it by using that method
        
        // we just need to calculate the maximum column number value and then need to give the answer
        
        // first calculate the values
        for(int j=0;j<matrix[0].size();j++)
        {
            for(int i=1;i<matrix.size();i++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j]=1+matrix[i-1][j];
                }
                else
                {
                    matrix[i][j]=0;
                }
            }
        }
        int ans=0;
        // so we just need to form the answer
        for(int i=0;i<matrix.size();i++)
        {
            vector<int>vec(matrix[i]);
            sort(vec.rbegin(),vec.rend());
            for(int i=0;i<vec.size();i++)
            {
                ans=max(ans,vec[i]*(i+1));
            }
        }
        return ans;
    }
};