class Solution {
public:
   int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
             int LCM = 1;
            for(int j = i; j < n; j++){
                LCM = lcm(LCM,nums[j]);
                if(LCM > k){
                    break;
                }
                if(LCM == k){
                    ans++;
                }
            }
        }
        return ans;
    }
};