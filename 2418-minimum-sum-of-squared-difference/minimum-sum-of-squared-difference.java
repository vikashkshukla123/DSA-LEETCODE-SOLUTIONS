class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int K = k1 + k2;
        int []diff = new int[100000 + 1];
        int n = nums1.length;
        for(int i = 0; i < n; i++){
            int difference = Math.abs(nums1[i] - nums2[i]);
            diff[difference]++;
        }

        for(int i = 100000; i > 0  && K > 0 ; i--){
            int countDiff = diff[i];
            int decrease = Math.min(K, countDiff);
            diff[i] -= decrease;
            diff[i-1] += decrease;

            K -= decrease;

        }
        long ans = 0;
        for(int i = 1; i <= 100000; i++){
            long val = (long) diff[i] * i * i;
            ans += val;

        }

        return ans;
    }
}