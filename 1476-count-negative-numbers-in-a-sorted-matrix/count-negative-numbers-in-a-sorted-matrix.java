class Solution {
    public int countNegatives(int[][] grid) {
        int ans = 0;
        int n = grid.length;
        int m = grid[0].length;

        for(int i = 0; i<n; i++){
            for(int j = m-1; j>=0; j--){
                if(grid[i][j] > 0){
                    break;
                }else if(grid[i][j] < 0){
                    ans++;
                }
            }
        }

       return ans;

    }
}