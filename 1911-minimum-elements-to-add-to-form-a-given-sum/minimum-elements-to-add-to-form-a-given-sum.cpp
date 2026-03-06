class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int n = nums.size();
        long long sum_we_got = 0;
        for(int i = 0; i<n; i++){
            sum_we_got += nums[i];
        }
        
        if(sum_we_got == goal){
            return 0;
        }

        long long sum_needed = goal - sum_we_got;

        long long original = abs(sum_needed);

        long long ans = ceil((double)original / limit);

        return (int)ans;
    }
};