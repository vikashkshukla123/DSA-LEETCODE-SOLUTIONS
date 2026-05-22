class Solution {
public:
int findTarget(int low, int high, int target, vector<int>&nums){
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}
int findMinimum(vector<int>&nums){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int mid;
    while(low < high){
        mid = low + (high - low)/2;
        if(nums[mid] > nums[high]){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    return low;
}
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = findMinimum(nums);

        int find1 = findTarget(0,idx-1,target,nums);
        int find2 = findTarget(idx, n-1, target,nums);

        if(find1 != -1){
            return find1;
        }

        return find2;


        
    }
};