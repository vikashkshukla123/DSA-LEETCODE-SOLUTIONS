class Solution {
    int min(int a, int b){
        if(a < b) return a;
        else return b;
     }
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long mini = 1e9;
        long long sum = 0;
        int total_negative = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int a = matrix[i][j];
                if(a < 0) total_negative++;
                sum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));

            }
        }
        if(total_negative % 2 == 0) return sum;
        else return sum - 2*(abs(mini));
        
    }
};