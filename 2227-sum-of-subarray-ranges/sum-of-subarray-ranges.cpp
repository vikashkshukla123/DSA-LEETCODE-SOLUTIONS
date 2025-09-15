class Solution {
    long long min(long long a, long long b){
        if(a < b) return a;
        return b;
    }
    long long max(long long a, long long b){
        if(a < b) return b;
        return a;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long min_val = 1e15;
            long long max_val = -1e15;
            for(int j = i; j<n; j ++){
                min_val = min(min_val,nums[j]);
                max_val = max(max_val, nums[j]);
                ans += (long long)(max_val - min_val);
                
            }
            
        }
        return ans;
    }
};