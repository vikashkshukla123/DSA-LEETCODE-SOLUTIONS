class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans = 1e9;

        for(int i = 0; i<=n-k; i++){
            int a = nums[i];
            int b = nums[i+k-1];

            int diff = b - a;
            ans = min(ans, diff);

        }
        return ans;
    }
};