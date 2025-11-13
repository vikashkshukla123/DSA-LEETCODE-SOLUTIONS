class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool>increasing(n,false);
        vector<bool>decreasing(n,false);
        vector<long long>prefix(n,0);
        vector<long long>suffix(n,0);

        increasing[0] = true;
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        decreasing[n-1] = true;

        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                increasing[i] = increasing[i-1];
                prefix[i] = prefix[i-1] + nums[i];
            }
        }
        for(int i = n-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                decreasing[i] = decreasing[i+1];
                suffix[i] = suffix[i+1] + nums[i];


            }
        }
        long long ans = LLONG_MAX;

        for(int i = 0; i<n-1; i++){
            if(increasing[i] == true && decreasing[i+1] == true){
                ans = min(ans, abs(prefix[i] - suffix[i+1]));
            }
        }
        return ans == LLONG_MAX ? -1 : ans;
    }
};