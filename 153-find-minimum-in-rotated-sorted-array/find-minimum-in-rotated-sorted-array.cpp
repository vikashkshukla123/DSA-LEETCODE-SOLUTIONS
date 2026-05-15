class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            }else{
                ans = min(ans,nums[high]);
                high = mid;
            }
        }

        return ans;
    }
};