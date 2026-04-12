class Solution {
    int solve(int number, int digit){
        int cnt = 0;
        while(number != 0){
            int val = number % 10;
            if(val == digit){
                cnt++;
            }

            number = number / 10;
        }

        return cnt;
    }
    public int countDigitOccurrences(int[] nums, int digit) {
        int n = nums.length;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int result = solve(nums[i],digit);
            ans += result;
        }

        return ans;
        
    }
}