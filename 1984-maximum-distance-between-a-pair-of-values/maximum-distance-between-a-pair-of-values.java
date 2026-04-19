class Solution {
    int binarySearch(int []nums2, int val, int i){
        int n = nums2.length;
        int low = 0;
        int high = n-1;
        int mid;
        int ans = -1;
        while(low <= high){
            mid = low + (high - low)/2;

            if(nums2[mid] >= val){
                ans = mid;
                low = mid + 1;

            }else{
                high = mid - 1;
            }
        }

        return ans;

    }
    public int maxDistance(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        int ans = (int)-1e9;
        for(int i = 0; i<n; i++){
            int val = nums1[i];
            int idx = binarySearch(nums2, val,i);
            if(idx < i) continue;
            ans = Math.max(ans, idx - i);
        }
        return ans == -1e9 ? 0 : ans;
    }
}