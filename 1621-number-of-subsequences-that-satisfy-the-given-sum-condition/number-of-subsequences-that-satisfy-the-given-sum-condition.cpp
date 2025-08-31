class Solution {
    int MOD = 1e9 + 7;
public:
void precompute(vector<int>&power_of_two ,int &n){
    power_of_two[0] = 1;
    for(int i = 1; i<n; i++){
        power_of_two[i] = (power_of_two[i-1]*2LL)%MOD;
    }
}
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> power_of_two(n);
        precompute(power_of_two,n);
        int ans = 0;
        int left = 0;
        int right = n-1;

        while(left <= right){
            if(nums[left] + nums[right] > target){
                right--;
            }
            else{
                ans = (ans + power_of_two[right-left])%MOD;
                left++;
                
            }
        }
        return ans;

        
    }
};