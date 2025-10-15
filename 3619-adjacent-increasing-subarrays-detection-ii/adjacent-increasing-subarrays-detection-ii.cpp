class Solution {
public:
bool isPossible(vector<int>&nums, int k){
    int n = nums.size();
    int curr = 1;
    int prev = 0;

    for(int i = 1; i<n; i++){
        if(nums[i] > nums[i-1]){
            curr++;
        }else{
            prev = curr;
            curr = 1;
        }

        if(curr >= 2*k){
            return true;
        }
        if(min(curr,prev) >= k){
            return true;
        }
    }
    return false;
}
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = n;
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(isPossible(nums,mid)){
                ans = max(ans,mid);
                left = mid + 1;

            }else{
                right = mid - 1;
            }
        }
    return ans;
    }
};