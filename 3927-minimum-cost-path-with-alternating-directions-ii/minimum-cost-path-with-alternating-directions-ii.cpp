class Solution {
public:
    int M, N;
    vector<vector<vector<long long>>> dp;

    long long solve(int row, int col, int seconds, vector<vector<int>>& waitCost){

        if(row >= N || col >= M){
            return 1e18;
        }

        if(row == N - 1 && col == M - 1){
            return 1LL * (row + 1) * (col + 1);
        }

        int parity = seconds % 2;

        if(dp[row][col][parity] != -1){
            return dp[row][col][parity];
        }

        long long ans = 1e18;

        if(parity == 1){
            long long cost = 1LL * (row + 1) * (col + 1);

            long long down = cost + solve(row + 1, col, seconds + 1, waitCost);
            long long right = cost + solve(row, col + 1, seconds + 1, waitCost);

            ans = min(down, right);

        } else {
            long long wait = waitCost[row][col];
            ans = wait + solve(row, col, seconds + 1, waitCost);
        }

        return dp[row][col][parity] = ans;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {

        N = waitCost.size();
        M = waitCost[0].size();

        dp.assign(N, vector<vector<long long>>(M, vector<long long>(2, -1)));

        return solve(0, 0, 1, waitCost);
    }
};