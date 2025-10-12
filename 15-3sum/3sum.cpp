class Solution { 
public:
void twoSum(vector<int>&nums, int k, vector<vector<int>>&result, int target){
    int i = k, j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] > target){
                j--;
            }else if(nums[i] + nums[j] < target){
                i++;
            }else{
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                result.push_back({-target, nums[i] , nums[j]});
                i++;
                j--;
            }

            
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int n1 = nums[i];
            int target = -n1;

            twoSum(nums,i+1, result, -nums[i]);


        }
        return result;
        
    }
};