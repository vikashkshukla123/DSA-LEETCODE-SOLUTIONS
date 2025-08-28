class Solution {
public:

void sortDiagonal(int row, int col, vector<vector<int>>&grid, bool  val){
    int i = row;
    int j = col;
    vector<int>vec;
    while(i<grid.size() && j<grid.size()){
        vec.push_back(grid[i][j]);
        i++;
        j++;
    }
    if(val == true){
        sort(vec.begin(),vec.end());
    }
    else{
        sort(vec.rbegin(),vec.rend());
        
    }
    i = row;
    j = col;
    for(int &val : vec){
        grid[i][j] = val;
        i++;
        j++;
    }
}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int r = 0;  r < n; r ++){
            sortDiagonal(r,0, grid, false);
        }
        for(int c = 1; c < n; c++){
            sortDiagonal(0,c, grid, true);
        }
        return grid;
        
    }
};