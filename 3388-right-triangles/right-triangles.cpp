class Solution {
public:
int calculaterow(int row,vector<vector<int>>& grid){
    int m = grid[0].size();
    int cnt = 0;
    for(int i = 0; i<m; i++){
        if(grid[row][i] == 1){
            cnt++;
        }
    }

    return cnt;
    
}

int calculatecol(int col, vector<vector<int>>& grid){
    int n = grid.size();
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(grid[i][col] == 1){
            cnt++;
        }
    }
    return cnt;
}
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        long long ans = 0;
        unordered_map<int,int>rows;
        unordered_map<int,int>cols;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    continue;
                }else{
                    int rows1 = 0;
                    int cols1 = 0;

                    if(rows.find(i) != rows.end()){
                        rows1 = rows[i];
                    }else{
                        rows1 = calculaterow(i,grid);
                        rows[i] = rows1;
                    }


                    if(cols.find(j) != cols.end()){
                        cols1 = cols[j];
                    }else{
                        cols1 = calculatecol(j,grid);
                        cols[j] = cols1;
                    }



                    ans += (rows1 - 1) * (cols1 - 1);



                }
            }
        }
        return ans;
    }
};