class Solution {
public:
int mod = 1e9 + 7;
int t[51][51][51];
int solve(int row_start, int col_start, int maxMove, int m, int n){
    if(maxMove < 0){
        return 0;
    }
    if(row_start < 0 || col_start < 0 || row_start >= m || col_start >= n){
        return 1;
    }
    if(t[row_start][col_start][maxMove] != -1){
        return t[row_start][col_start][maxMove];
    }

    int case1 = solve(row_start + 1, col_start, maxMove - 1, m, n);
    int case2 = solve(row_start, col_start + 1,maxMove - 1, m, n);
    int case3 = solve(row_start - 1, col_start, maxMove - 1, m, n);
    int case4 = solve(row_start, col_start - 1, maxMove - 1, m, n);
    long long ans = 1LL * case1 + case2 + case3 + case4;
    return t[row_start][col_start][maxMove] = ans % mod;



}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t,-1,sizeof(t));
        return solve(startRow, startColumn,maxMove, m,n);
        
    }
};