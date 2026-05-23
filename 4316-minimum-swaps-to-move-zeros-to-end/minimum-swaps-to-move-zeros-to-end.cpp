class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cnt0++;
            }
        }

        int ans = 0;
        int j = cnt0;
        int k = n-1;
        while(j -- ){
            if(nums[k] != 0){
                ans++;
            }
            k--;


        }
        return ans;
    }
};