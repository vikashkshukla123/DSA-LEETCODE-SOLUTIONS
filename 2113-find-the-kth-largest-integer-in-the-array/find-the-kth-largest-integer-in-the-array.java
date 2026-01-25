import java.math.BigInteger;
import java.util.Arrays;
class Solution {
    public String kthLargestNumber(String[] nums, int k) {
       int n = nums.length;
       BigInteger[] arr = new BigInteger[n];
       for(int i = 0; i<n; i++){
          arr[i] = new BigInteger(nums[i]);
       }
       Arrays.sort(arr);
       String s = String.valueOf(arr[n-k]);
       return s;
        
    }
}