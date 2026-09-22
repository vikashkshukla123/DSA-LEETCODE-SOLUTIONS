class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int m = queries.length;
        int n = nums.length;
        int []correct = new int[n];
        correct[0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i-1] % 2 == 0 && nums[i] % 2 == 0){
                correct[i] = 0;
            }else if(nums[i-1] % 2 == 1 && nums[i] % 2 == 1){
                correct[i] = 0;
            }else{
                correct[i] = 1;
            }
        }

        int []prefixCorrect = new int[n];
        prefixCorrect[0] = correct[0];
        for(int i = 1; i < n; i++){
            prefixCorrect[i] = correct[i] + prefixCorrect[i-1];
        }
        boolean [] b = new boolean[m];
        for(int i = 0; i < m; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            if(start - end + 1 == 1){
                b[i] = true;
                continue;
            }

            int totalElem = end - start + 1;
            int prefixSum = prefixCorrect[end] - prefixCorrect[start];
            if(prefixSum == totalElem - 1){
                b[i] = true;
            }else{
                b[i] = false;
            }

        }

        return b;
    }
}