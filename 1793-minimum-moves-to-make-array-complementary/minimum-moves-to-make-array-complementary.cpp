class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>diff(2*limit + 2,0);
        for(int i = 0; i < n/2; i++){
            int a = nums[i];
            int b = nums[n-1-i];

            int min_val = min(a,b) + 1;
            int max_val = max(a,b) + limit;

            diff[2] += 2;
            diff[2*limit + 1] -= 2;

            diff[min_val] += -1;
            diff[max_val + 1] -= -1; 

            diff[a + b] += -1;
            diff[a + b + 1] -= -1;
        }
        int result = 1e9;
        for(int sum = 2; sum <= 2 * limit; sum++){
            diff[sum] += diff[sum-1];
            result = min(result,diff[sum]);
        }
return result;
        
    }
};