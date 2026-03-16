class Solution {
public:
bool binarySearch(int left, int right, vector<int>&nums, int target){
    while(left <= right){
        int mid = left + (right - left)/2;

        if(nums[mid] == target){
            return true;
        }else if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    } 

    return false;
}
int getPivot(vector<int>&nums){
    int left = 0;
    int right = nums.size() - 1;
    while(left < right && nums[left] == nums[left+1]){
        left++;
    }

    while(left < right && nums[right] == nums[right - 1]){
        right--;
    }

   int ans;
    while(left < right){
        int mid = left + (right - left)/2;

        if(nums[mid] > nums[right]){
            left = mid + 1;
        }else{
            right = mid;
            ans = mid;

        }
    }
    return right;
}
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = getPivot(nums);
        if(nums[idx] == target){
            return true;
        }
        bool ans = binarySearch(idx+1,n-1,nums,target);

        if(ans == true){
            return true;
        }

        bool ans1 = binarySearch(0,idx-1,nums,target);
        if(ans1 == true){
            return true;
        }


        return false;
    }
};