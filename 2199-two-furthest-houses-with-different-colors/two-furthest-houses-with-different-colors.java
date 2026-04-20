class Solution {
    public int maxDistance(int[] colors) {
        int n = colors.length;
        int ans = (int)-1e9;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                if(colors[i] != colors[j]){
                ans = Math.max(ans, Math.abs(i - j));
                }
            }
        }
        return ans;
    }
}