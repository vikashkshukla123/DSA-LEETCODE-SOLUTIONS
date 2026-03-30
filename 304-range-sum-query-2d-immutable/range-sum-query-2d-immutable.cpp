class NumMatrix {
public:
int N;
int M;
vector<vector<int>>prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        N = matrix.size();
        M = matrix[0].size();
        prefixSum = vector<vector<int>>(N,vector<int>(M,0));
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                prefixSum[i][j] = (i > 0 ? prefixSum[i-1][j] : 0) + (j  > 0  ? prefixSum[i][j-1] : 0) - (i > 0 && j > 0 ? prefixSum[i-1][j-1] : 0) + matrix[i][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefixSum[row2][col2] - (col1 > 0  ? prefixSum[row2][col1-1] : 0) - (row1 > 0 ? prefixSum[row1-1][col2] : 0) + (row1 > 0  && col1 > 0 ? prefixSum[row1-1][col1-1]: 0);

        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */