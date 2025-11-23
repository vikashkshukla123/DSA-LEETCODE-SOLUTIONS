class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int l = n * m;

        vector<int> p(l);
        int idx = 0;

        // Flatten the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[idx++] = grid[i][j];
            }
        }

        k = k % l; // Important: effective rotation

        if (k == 0) return grid; // no shift needed

        // Rotate right by k
        reverse(p.begin(), p.end());
        reverse(p.begin(), p.begin() + k);
        reverse(p.begin() + k, p.end());

        // Convert back to 2D
        vector<vector<int>> ans(n, vector<int>(m));
        idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = p[idx++];
            }
        }

        return ans;
    }
};
