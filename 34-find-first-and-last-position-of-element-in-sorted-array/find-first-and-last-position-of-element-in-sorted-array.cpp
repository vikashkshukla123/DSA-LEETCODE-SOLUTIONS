class Solution {
    
public:
int findLowest(vector<int>&nums, int target){
        int lowest = -1;
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] == target){
                lowest = mid;
                high = mid - 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else {
                high = mid - 1;
            }

        }
        return lowest;
    }

    int findHighest(vector<int>&nums, int target){
        int highest = -1;
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] == target){
                highest = mid;
                low = mid  +  1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else {
                high = mid - 1;
            }

        }
        return highest;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lowest = findLowest(nums,target);
        int highest = findHighest(nums,target);
        return {lowest,highest};
        
    }
};