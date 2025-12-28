class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        int n = happiness.length;
        long ans = 0;
        int i = n-1;
        int cnt = 1;
        while(k > 0){
            if(happiness[i] < 0){
                break;
            }
            ans += happiness[i];
            if(i > 0){
                happiness[i-1] = happiness[i-1] - cnt;
            }
            k--;
            i--;
            cnt++;

        }

        return ans;
    }
}