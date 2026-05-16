class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left < n-1 && nums[left+1] == nums[left]){
            left++;
        }
        while(right >  0 && nums[right] == nums[right-1]){
            right--;
        }
        int low = left;
        int high = right;

        int result_index = 0;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid]  < nums[result_index]){
                result_index = mid;
            }
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else{
                high = mid-1;
            }
        }

        return nums[result_index];
    }
};