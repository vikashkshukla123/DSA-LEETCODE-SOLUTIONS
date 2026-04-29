class Solution {
public:
typedef long long ll;
int n;
ll t[2][101][101];
ll solve(bool prevTaken, int prevHeight, int col,vector<vector<int>>& grid, vector<vector<ll>>&colPrefixSum){
    if(col == n) return 0;
    ll result = 0;
    if(t[prevTaken][prevHeight][col] != -1){
        return t[prevTaken][prevHeight][col];
    }
    for(int height = 0; height <= n; height++){
        ll prevColScore = 0;
        ll currColScore = 0;

        if(!prevTaken && col - 1 >= 0 &&  height > prevHeight){
            prevColScore += colPrefixSum[height][col] - colPrefixSum[prevHeight][col];
        }

        if(prevHeight > height){
            currColScore += colPrefixSum[prevHeight][col+1] - colPrefixSum[height][col+1];
        }

        ll currColScoreTaken = prevColScore + currColScore + solve(true,height, col + 1, grid, colPrefixSum);

        ll currColScoreNotTaken = prevColScore + solve(false,height, col+1, grid, colPrefixSum);


        result = max({result, currColScoreTaken,currColScoreNotTaken});
    }
    return t[prevTaken][prevHeight][col] = result;
}
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        memset(t,-1,sizeof(t));
        vector<vector<ll>>colPrefixSum(n+1,vector<ll>(n+1,0));
        for(int col = 1; col <= n; col++){
            for(int row = 1; row <= n; row++){
                colPrefixSum[row][col] = colPrefixSum[row-1][col] + grid[row-1][col-1];

            }
        }

        return solve(false,0,0,grid,colPrefixSum);
        
    }
};