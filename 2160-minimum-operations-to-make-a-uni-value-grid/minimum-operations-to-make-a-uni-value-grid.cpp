class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans;
        int remainder = grid[0][0] % x;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]%x != remainder) return -1;
                ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        int k = ans.size();
        int median = k/2;
        int steps = 0;
        for(int i = 0; i< ans.size(); i++){
            steps += abs(ans[i] - ans[median])/x;
        }
        return steps;
    }
};