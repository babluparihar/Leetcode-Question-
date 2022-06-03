class NumMatrix {
public:
    vector<vector<long long>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        dp.resize(matrix.size()+1,vector<long long>(matrix[0].size()+1,0));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                dp[i+1][j+1]=matrix[i][j]+(dp[i][j+1]+dp[i+1][j]-dp[i][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long first=dp[row1+1][col1+1];
        long long second=dp[row2+1][col2+1];
        long long third=dp[row2+1][col1];
        long long four=dp[row1][col2+1];
        long long five=dp[row1][col1];
        return second-third-four+five;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */