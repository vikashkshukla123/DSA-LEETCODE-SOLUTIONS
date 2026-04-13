class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        for(int i = 0; i<m; i++){
            int sum = 0;
            for(int j = 0; j<n; j++){
                sum += matrix[i][j];
            }

            ans.push_back(sum);

        }
        return ans;
    }
};