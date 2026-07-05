class Solution {
public:
int mod = 1e9+7;
int solve2(int row, int col, int sumTillNow, int sumNeeded, vector<vector<char>>&grid,vector<vector<vector<int>>>&dp2){
    int n = grid.size();
    int m = grid[0].size();

    if(row == 0 && col == 0 && sumTillNow == sumNeeded){
        return 1;
    }
    

    if(row < 0 || col < 0 || grid[row][col] == 'X') return 0;

    sumTillNow += grid[row][col] - '0';
    if(sumTillNow > sumNeeded) return 0;

    if(dp2[row][col][sumTillNow] != -1){
        return dp2[row][col][sumTillNow];
    }
    int up = solve2(row - 1, col, sumTillNow, sumNeeded, grid,dp2);
    int left = solve2(row, col - 1, sumTillNow, sumNeeded, grid,dp2);
    int diagonal = solve2(row - 1, col - 1, sumTillNow, sumNeeded, grid,dp2);


    return dp2[row][col][sumTillNow] = (up + left + diagonal) % mod;
}
int solve1(int row, int col, vector<vector<char>>&grid,vector<vector<int>>&dp1){
    int n = grid.size();
    int m = grid[0].size();

    if(row == 0 && col == 0){
        return grid[row][col] - '0';
    }

    if(row < 0 || col < 0 || grid[row][col] == 'X'){
        return -1e9;
    }

    if(dp1[row][col] != -1){
        return dp1[row][col];
    }


    
    int left = solve1(row, col-1,grid,dp1);
    int up =  solve1(row-1, col, grid,dp1);
    int diagonal = solve1(row - 1, col - 1, grid,dp1);


    return dp1[row][col] = grid[row][col] - '0' +  max(left, max(up, diagonal));



    
    
}
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<char>>grid(n,vector<char>(m,'*'));
        for(int i = 0; i < n; i++){
            string s = board[i];
            
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0 || i == n-1 && j == m-1){
                grid[i][j] = '0';
                continue;
            }
                grid[i][j] = board[i][j];
            }
        }
        vector<vector<int>>dp1(n,vector<int>(m,-1));
        vector<vector<vector<int>>>dp2(n,vector<vector<int>>(m,vector<int>(2000,-1)));

        

        int ans = solve1(n-1,m-1,grid,dp1);
        if(ans < 0) return {0,0};

        int path = solve2(n-1,m-1,0,ans,grid,dp2);
        
    


        return {ans,path};


    }
};