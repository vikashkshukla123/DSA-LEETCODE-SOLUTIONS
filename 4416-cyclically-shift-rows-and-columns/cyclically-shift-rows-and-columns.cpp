class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>temp = grid;
        int m = rowShift.size();
        for(int i = 0; i < m; i++){
            for(int col = 0; col < n; col++){
                int newc = (col - rowShift[i] + n) % n;
                temp[i][newc] = grid[i][col];
            }
        }

        vector<vector<int>>temp2 = temp;
        int k = colShift.size();
        for(int i = 0; i < k; i++){
            for(int row = 0; row < n; row++){
                int newr = (row - colShift[i] + n) % n;
                temp2[newr][i] = temp[row][i];
            }
        }
        return temp2;
        
    }
};