class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                cnt0++;
            }
        }
        if(cnt0 > n/3) return 0;
        for(int i = 0; i<n; i++){
            if(nums[i] < 0){
                nums[i] = nums[i]*-1;
            }
        }
        sort(nums.begin(),nums.end());
        int num1 = nums[n-1];
        int num2 = nums[n-2];

        return 1e5*num1*num2;
        
    }
};