class Solution {
    public int maxSubarray(int[] nums) {
        int n = nums.length;
        if(n <= 2) return n;
        int freq[] = new int[601];
        for(int i = 0; i <= 600; i++){
            freq[i] = 0;
        }
        int ans = 0;
        int left = 0;
        int right = 0;
        while(right < n){
            freq[nums[right]]++;

            int case1 = nums[right];
            while(left < n  && right - left + 1 >= 3){
                boolean found = false;
                for(int num1 = 1; num1 < case1; num1++){
                    int val1 = num1;
                    int val2 = case1 - val1;

                    if(val1 == val2 && freq[val1] < 2) continue;

                
                    if(freq[val1] > 0 && freq[val2] > 0 ){
                        found = true;
                        freq[nums[left]]--;
                        left++;
                        break;

                    }
                }
                if(!found){
                    break;
                }

            }
            int case2 = nums[right];
            while(left < n && right - left + 1 >= 3){
            boolean found = false;
            for(int i = 1; i + case2 <= 500; i++){
                if(i == case2) {
    if(freq[i] >= 2 && freq[i + case2] > 0) {
        found = true;
        freq[nums[left]]--;
        left++;
        break;
    }
}
else if(freq[i] > 0 && freq[i + case2] > 0) {
    found = true;
    freq[nums[left]]--;
    left++;
    break;
}

            }
                

               if(!found){
                break;
               }
            }

          ans = Math.max(ans, right - left + 1);
          

          right++;



        }
        return ans;
    }
}