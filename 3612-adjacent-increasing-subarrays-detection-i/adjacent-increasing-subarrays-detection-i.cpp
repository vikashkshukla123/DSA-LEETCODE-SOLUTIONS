class Solution {
public:
bool isPossible(int idx,vector<int>&nums, int k){
    int i_idx = idx;
    int j_idx = idx + k;

    bool increasing = true;

    for(int i = idx+1; i<idx + k; i++){
        if(nums[i] <= nums[i-1]){
            increasing = false;
            break;
        }
       

    }


    bool inc = true;
    for(int i = idx + k + 1 ; i<idx + 2*k; i++){
        if(nums[i] <= nums[i-1]){
            inc = false;
        }
    }

    if(increasing == true && inc == true){
        return true;

    }
    return false;
}
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<=n-2*k; i++){
            if(isPossible(i,nums,k)){
                return true;
                break;
            }

        }
        return false;
        
        
    }
};