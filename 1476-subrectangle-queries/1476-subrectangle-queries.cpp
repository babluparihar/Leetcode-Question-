class SubrectangleQueries {
public:
    vector<vector<int>>dp;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        for(auto i:rectangle)
        {
            vector<int>vec;
            for(auto j:i)
            {
                vec.push_back(j);
            }
            dp.push_back(vec);
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1;i<=row2;i++)
        {
            for(int j=col1;j<=col2;j++)
            {
                dp[i][j]=newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return dp[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */