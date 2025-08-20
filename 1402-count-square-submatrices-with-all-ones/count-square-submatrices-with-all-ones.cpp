class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int sub_matrix = 0;
        vector<vector<int>>maximal_sq(n+1,vector<int>(m+1,0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(matrix[i-1][j-1] == 1){
                    maximal_sq[i][j] = 1 + min({maximal_sq[i-1][j-1], maximal_sq[i-1][j], maximal_sq[i][j-1]});
                    sub_matrix += maximal_sq[i][j];
                }
            }

        }
        return sub_matrix;
        
    }
};