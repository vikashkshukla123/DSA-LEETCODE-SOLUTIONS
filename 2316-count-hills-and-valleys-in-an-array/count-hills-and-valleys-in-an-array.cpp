class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i<n-1; i++){
            if(nums[i] == nums[i-1]) continue;
        
        int j = i-1;
        int k = i+1;
        while(k < n && nums[i] == nums[k]) k++;
        while(j >= 0 && nums[i] == nums[j]) j--;

        if(k >= n || j < 0) continue;

        if(nums[i] > nums[j] && nums[i] > nums[k]) ans++;
        else if(nums[i] < nums[j] && nums[i] < nums[k]) ans++;
        }
        return ans;
        
    }
};