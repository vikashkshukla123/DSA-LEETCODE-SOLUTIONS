class Solution {
public:
    bool solve(int idx, long double product, long double target, vector<int>& nums){
        int n = nums.size();

        if(abs(product - target) < 1e-9){
            return true;
        }

        if(idx == n) return false;

        // take
        if(product * nums[idx] <= target){
            if(solve(idx + 1, product * nums[idx], target, nums)) return true;
        }

        // not take
        if(solve(idx + 1, product, target, nums)) return true;

        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long double target_square = (long double)target * target;

        long double check = 1;
        for(int x : nums){
            check *= x;
        }

        if(abs(check - target_square) > 1e-9){
            return false;
        }

        return solve(0, 1, target, nums);
    }
};