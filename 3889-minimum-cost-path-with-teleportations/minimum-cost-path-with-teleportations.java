class Solution {
    public int minCost(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;

        int dp[][] = new int[n][m];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i],Integer.MAX_VALUE);
        }

        dp[n-1][m-1] = 0;
        int max_value = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                max_value = Math.max(max_value,grid[i][j]);
            }
        }

        int[]teleportations = new int[max_value + 1];

        for(int i = 0; i <= max_value; i++){
            teleportations[i] = Integer.MAX_VALUE;
        }

        for(int tp = 0; tp <= k; tp++){
            for(int i = n-1 ; i >= 0; i--){
                for(int j = m-1; j >= 0; j--){
                    if(i+1 < n){
                        dp[i][j] = Math.min(dp[i][j], grid[i+1][j] + dp[i+1][j]);
                    }

                    if(j + 1 < m){
                        dp[i][j] = Math.min(dp[i][j], grid[i][j+1] + dp[i][j+1]);
                    }

                    if(k > 0){
                        dp[i][j] = Math.min(teleportations[grid[i][j]], dp[i][j]);
                    }
                }
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    teleportations[grid[i][j]] = Math.min(teleportations[grid[i][j]],dp[i][j]);
                }
            }

            for(int i = 1; i < teleportations.length; i++){
                teleportations[i] = Math.min(teleportations[i],teleportations[i-1]);
            }


        }
        return dp[0][0];

        
    }
}