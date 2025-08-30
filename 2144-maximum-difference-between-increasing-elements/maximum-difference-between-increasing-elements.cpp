class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                int diff = nums[j] - nums[i];
                if(diff > 0){
                maxi = max(maxi,diff);
                }
            }
        }
        return maxi;
        
    }
};