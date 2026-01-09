class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>result;
        for(int i = 0; i<m; i++){
            vector<int>ans;
            for(int j = 0; j<n; j++){
                ans.push_back(matrix[j][i]);

            }
            result.push_back(ans);
        
        }
        return result;
        
    }
};