class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int low_x = 1e9;
    int high_x = -1;
    int low_y = 1e9;
    int high_y = -1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1){
                low_x = min(low_x, i);
                high_x = max(high_x, i);
                low_y = min(low_y, j);
                high_y = max(high_y, j);
            }
        }
    }
    return (high_x - low_x + 1)*(high_y - low_y + 1);
        
    }
};