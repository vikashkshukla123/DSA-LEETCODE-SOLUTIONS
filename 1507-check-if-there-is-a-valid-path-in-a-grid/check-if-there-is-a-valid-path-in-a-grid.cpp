class Solution {
public:
int n,m;
unordered_map<int,vector<vector<int>>>mp;
bool isValid(int row, int col, vector<vector<bool>>&visited){
    return (row >= 0 && row < n && col >= 0 && col < m && !visited[row][col]);
}
bool solve(int row, int col, vector<vector<bool>>&visited, vector<vector<int>>&grid){
    visited[row][col] = true;
    if(row == n-1 && col == m-1){
        return true;
    }
    int value = grid[row][col];
    vector<vector<int>>&dir = mp[value];
    for(int i = 0; i<2; i++){
        int newr = row + dir[i][0];
        int newc = col + dir[i][1];

        if(isValid(newr,newc,visited)){
            bool canGo = false;
            int val = grid[newr][newc];
            vector<vector<int>>&dir2 = mp[val];

            for(int j = 0; j<2; j++){
                if(newr + dir2[j][0] == row && newc + dir2[j][1] == col){
                    canGo = true;
                    break;
                }
                
            }

            if(canGo){
                if(solve(newr,newc, visited, grid)){
                    return true;
                }
            }

            
        }

        
    }
    return false;

}
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
mp[1] = {{0,1},{0,-1}};
mp[2] = {{-1,0},{1,0}};
mp[3] = {{0,-1},{1,0}};
mp[4] = {{0,1},{1,0}};
mp[5] = {{0,-1},{-1,0}};
mp[6] = {{0,1},{-1,0}};
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        return solve(0,0,visited,grid);
        
        
    }
};