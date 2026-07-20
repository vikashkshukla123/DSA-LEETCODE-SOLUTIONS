class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                ans.push_back(grid[i][j]);
            }
        }
        int ans_size = n * m;

        for(int i = 0; i < k; i++){
            reverse(ans.begin(), ans.begin() + n*m - 1);
            reverse(ans.begin(),ans.end());
            
        }
        
        vector<vector<int>>result(n,vector<int>(m,0));
        int step = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = ans[step];
                step++;
            }
        }

        return result;
    }
};