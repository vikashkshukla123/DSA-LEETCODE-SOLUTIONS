class Solution {
    int solve(int i, int j, int[] stoneValue,int[]prefixSum,int [][]dp){
        if(i > j){
            return 0;
        }
        if(i == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
       
        int ans = 0;
        for(int split = i; split < j; split++){
            int sum1 = prefixSum[split] - (i > 0 ? prefixSum[i-1] : 0);
            int sum2 = prefixSum[j] - prefixSum[split];

            if(sum1 > sum2){
                ans = Math.max(ans, sum2 + solve(split + 1, j,stoneValue,prefixSum,dp));
            }else if(sum1 < sum2){
                ans = Math.max(ans, sum1 + solve(i, split, stoneValue, prefixSum,dp));

            }else {
                ans = Math.max(ans, sum1 + Math.max(solve(split + 1, j, stoneValue,prefixSum,dp),solve(i, split, stoneValue, prefixSum,dp)));
            }


        }

        return dp[i][j] =  ans;
    }
    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;
        int []prefixSum = new int[n];
        prefixSum[0] = stoneValue[0];
        int[][] dp = new int[n+1][n+1];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i],-1);
        }
        for(int i = 1; i < n; i++){
            prefixSum[i] = stoneValue[i] + prefixSum[i-1];
        }
        return solve(0,n-1,stoneValue,prefixSum,dp);
    }
}