class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int z_view_area = 0;
        int x_view_area = 0;
        int y_view_area = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    z_view_area++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            int max_cube = 0;
            for(int j = 0; j < m; j++){
                max_cube = max(max_cube, grid[i][j]);
            }

            x_view_area += max_cube;
        }


         for(int j = 0; j < m; j++){
            int max_cube = 0;
            for(int i = 0; i < n; i++){
                max_cube = max(max_cube, grid[i][j]);
            }

            y_view_area += max_cube;
        }
        return (x_view_area + y_view_area + z_view_area);
    }
};