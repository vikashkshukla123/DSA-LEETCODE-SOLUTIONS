class Solution {
public:
    int solve(int idx1, int idx2, vector<int>& arr, vector<vector<int>>& dp) {
        int n = arr.size();

        if (idx2 >= n) return 0;

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        int sum_we_need = arr[idx1] + arr[idx2];
        int length = 2;

        int idx = lower_bound(arr.begin() + idx2 + 1, arr.end(), sum_we_need) - arr.begin();
        if(idx < n && arr[idx] == sum_we_need){
            length = max(length,1 + solve(idx2, idx, arr, dp));
        }

        return dp[idx1][idx2] = length;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int length = solve(i, j, arr, dp);
                ans = max(ans, length);
            }
        }

        return ans >= 3 ? ans : 0;
    }
};