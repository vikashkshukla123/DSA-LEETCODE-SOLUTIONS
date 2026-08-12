class Solution {
public:
bool isPossible(int start, int end, vector<int>&nums){
    bool increasing1 = true;
    bool increasing2 = true;
    int n = nums.size();
    if(start == 0 && end != n-1){
        for(int j = end + 1; j < n-1; j++){
            if(nums[j]  >=  nums[j+1]) return false;
        }
    }

    if(end == n-1 && start != 0){
        for(int j = 1; j < start; j++){
            if(nums[j]  <= nums[j-1]){
                return false;
            }
        }
    }

    if(start != 0 && end != n-1){
         if(nums[start-1] >= nums[end + 1]){
        return false;
    }
        for(int j = 1; j < start; j++){
            if(nums[j]  <= nums[j-1]){
                increasing1 = false;
                break;
            }
        }


        for(int j = end + 1; j < n-1; j++){
            if(nums[j] >= nums[j+1]){
                increasing2 = false;
                break;
            }
        }
    }

return (increasing1 && increasing2);

    


}
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPossible(i,j,nums)){
                    ans++;
                }
            }
        }
        return ans;
    }
};