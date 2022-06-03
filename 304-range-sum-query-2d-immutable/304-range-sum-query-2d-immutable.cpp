class NumMatrix {
public:
    vector<vector<int>> prefix;
    
    NumMatrix(vector<vector<int>>& matrix) {
        prefix.resize(matrix.size()+2,vector<int>(matrix[0].size()+2,0));
        
        for(int i=1;i<=matrix.size();++i){
            prefix[i][1] = prefix[i-1][1] + matrix[i-1][0];
        }
        for(int j=1;j<=matrix[0].size();++j){
            prefix[1][j] = prefix[1][j-1] + matrix[0][j-1];
        }
        
        for(int i=2;i<=matrix.size();++i){
            for(int j=2;j<=matrix[0].size();++j){
                prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        
        return (prefix[row2][col2]-prefix[row2][col1-1] - prefix[row1-1][col2] + prefix[row1-1][col1-1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */