class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        long long sum = 0;
        sort(nums.begin(),nums.end());
        int idx = n-1;
        while(mul != 0 && k > 0){
            long long ans = 1LL * nums[idx] * mul;
            sum += ans;
            mul = mul - 1;
            k--;
            idx--;

        }

        if(k == 0){
            return sum;
        }

        while(k > 0 && idx >= 0){
            sum += nums[idx];
            k--;
            idx--;
        }

        
return sum ;

    }
};