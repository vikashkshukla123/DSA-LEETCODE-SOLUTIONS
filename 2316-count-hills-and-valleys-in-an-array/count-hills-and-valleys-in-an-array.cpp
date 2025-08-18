class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        int ans = 0;
        while(j + 1 < n){
            if((nums[j] > nums[i] && nums[j] > nums[j+1]) or (nums[j] < nums[i] && nums[j] < nums[j+1])){
                ans++;
                i = j;

            }
            j++;
        }
        return ans;
        
    }
};